
// HELPERS
var d = document
var $ = d.getElementById.bind(d)
var	L = function (tagName, attrs) {
	var el

	el = d.createElement(tagName)
	for (var k in attrs) {
		el[k] = attrs[k]
		el.setAttribute(k, attrs[k])
	}
	return el
}
var propOf = function (prop) {
	return function (it) {
		return it[prop]
	}
}

// MAIN CODE
function run() {
	var map = runMap($('cells'), $('val'), $('width'), $('height'))
	var values = runValues($('values'), $('val'),
		[' ', 'S', '+']
	)
	var exporter = runExporter(map, $('export'))
}

function runMap(el, valEl, widthEl, heightEl, valuesEl) {
	// {x: width, y: height}
	var map = new Map(el, valEl, +widthEl.value, +heightEl.value)

	widthEl.addEventListener('keyup', function () {
		var val = Math.abs(+widthEl.value)

		if (val < 1 || isNaN(val))
			val = 1
		map.resize(val, map.y)
	})
	heightEl.addEventListener('keyup', function () {
		var val = Math.abs(+heightEl.value)

		if (val < 1 || isNaN(val))
			val = 1
		map.resize(map.x, val)
	})

	return map
}

function runExporter(map, values, exportEl) {
	var exporter = new Exporter(map, values, exportEl)
	return exporter
}

function runValues(el, valEl, values) {
	var values = new ValueManager(el, valEl, values)
	return values
}

// CODE
// -- EVENT DISPATCHER
function EventDispatcher() {
	var callbacks = {}

	this.on = function(name, cb) {
		if (!callbacks[name])
			callbacks[name] = []
		callbacks[name].push(cb)
	}

	this.trigger = function(name) {
		if (!callbacks[name])
			return
		var cb = callbacks[name]
		for (var i = cb.length - 1; i >= 0; i--) {
			cb[i](this)
		}
	}
}

// -- EXPORTER
function Exporter(map, exportEl) {
	map.on('change', this.updateBinding.bind(this))
	this._attach(exportEl)
}

Exporter.prototype.updateBinding = function(map) {
	this.exportEl.innerHTML = map.cells.map(function (cells) {
		return cells.join('')
	}).join("\n")
}

Exporter.prototype._attach = function(exportEl) {
	this.exportEl = exportEl
}

// -- MAP
function Map(el, valEl, x, y) {
	EventDispatcher.call(this)

	this._attach(el, valEl)
	this.resize(x, y)
}

Map.prototype.resize = function(x, y) {
	this.x = x
	this.y = y

	if (this.cells)
		this.cells.length = y
	else
		this.cells = new Array(y)

	for (var i = 0; i < this.y; ++i) {
		if (this.cells[i])
			this.cells[i].length = this.x
		else
			this.cells[i] = new Array(this.x)

		for (var j = 0; j < this.x; ++j) {
			if (!this.cells[i][j])
				this.cells[i][j] = ' '
		}
	}

	this._draw()
	this.trigger('change')
};

Map.prototype._draw = function() {
	var tr, td

	this.el.innerHTML = ''

	for (var i = 0; i < this.y; ++i) {
		tr = d.createElement('tr')
		for (var j = 0; j < this.x; ++j) {
			tr.appendChild(L('td', {
				'data-y': i, 'data-x': j,
				'className': 'cell',
				// @TODO background n stuff
				'innerHTML': this._htmlFor(this.cells[i][j])
			}))
		}
		this.el.appendChild(tr)
	}
}

Map.prototype._htmlFor = function(sigil) {
	return sigil
};

Map.prototype._attach = function(el, valEl) {
	var _this = this
	this.el = el

	el.addEventListener('click', function (e) {
		var dataset, x, y

		if (e.target.tagName.toLowerCase() !== 'td')
			return

		dataset = e.target.dataset
		_this.cells[dataset.y][dataset.x] = valEl.value
		_this.trigger('change')
		_this._draw()
	})
}

// -- VALUE MANAGER
function ValueManager(el, valEl, values) {
	this.values = values
	this._attach(el, valEl)

	this.draw()
}

ValueManager.prototype._attach = function(el, valEl) {
	this.el = el

	el.addEventListener('click', function (e) {
		if (e.target.tagName.toLowerCase() !== 'span')
			return

		valEl.value = e.target.dataset.value
	})
}

ValueManager.prototype.draw = function() {
	var value
	var valueEls = []

	for (var i = this.values.length - 1; i >= 0; i--) {
		value = this.values[i]
		valueEls.push(L('span', {
			'className': 'cell',
			'data-value': value,
			'innerHTML': '[' + value + ']'
		}))
	};

	this.el.innerHTML = valueEls.map(propOf('outerHTML')).join(' &bull; ')
}

// GO
run()