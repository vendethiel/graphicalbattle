#include "main.h"

void entity_clear(t_entity* entity);

static t_entity* entity_make_monster(t_monster* monster, int x, int y) {
  t_entity *entity;

  entity = xcalloc(1, sizeof *entity);
  entity->type = entity_monster;
  entity->monster = monster;
  entity->x = x;
  entity->y = y;
  return entity;
}

static void entity_prepend(t_entity** list, t_entity* new) {
  if (*list) {
    new->next = *list;
  }
  *list = new;
}

static void entity_list_remove(t_entity** list, t_entity* toremove) {
  t_entity* toclear,* head;

  toclear = NULL;
  head = *list;
  if (head == toremove) {
    toclear = head;
    *list = head->next;
  } else {
    for (; head && head->next; head = head->next) {
      if (head->next == toremove) {
        toclear = head->next;
        head->next = head->next->next;
        break;
      }
    }
  }

  if (toclear) {
    entity_clear(toclear);
  }
}

static int is_data(t_entity* entity, e_entity_type type, void* ptr) {
  switch (type) {
    case entity_monster:
      return entity->monster == ptr;
      break;

    default:
      err("Invalid entity type");
  }
}

void entity_remove(t_entity** list, e_entity_type type, void* ptr) {
  for (t_entity* head = *list; head; head = head->next) {
    if (head->type == type && is_data(head, type, ptr)) {
      entity_list_remove(list, head);
      break;
    }
  }
}

t_entity* entity_at(t_entity* head, int x, int y) {
  for (; head; head = head->next)
    if (head->x == x && head->y == y)
      break;
  return head;
}

// TODO should return 0/1 if we should move to the cell or not??
void entity_trigger(t_game* game, t_entity* entity) {
  switch (entity->type) {
    case entity_monster:
      fight_start(game, entity->monster);
      break;

    default:
      err("Invalid entity type");
  }
}

// TODO clear entit{y,ies}
void entity_clear(t_entity* entity) {
  free(entity);
}

// TODO entity/display.c file or w/e
t_sprite* entity_get_sprite(t_entity* entity) {
  switch (entity->type) {
    case entity_monster:
      return monster_get_sprite(entity->monster);

    default:
      err("Invalid entity type");
  }
}

// TODO entity/parsing.c file or w/e
static int nextint(char* sep, char** saveptr) {
  char* str;

  str = strtok_r(NULL, sep, saveptr);
  if (!str) {
    err("Couldn't parse entity file");
  }
  return strtol(str, NULL, 10);
}
t_entity* entities_from_string(t_game* game, char* str) {
  char *saveptr, * kind;
  t_entity *head, * new;

  head = NULL;
  kind = strtok_r(str, " ", &saveptr);
  do {
    new = NULL;
    if (!strcmp(kind, "mob")) {
      int x, y;

      x = nextint(" ", &saveptr);
      y = nextint(" ", &saveptr),
      kind = strtok_r(NULL, "\n", &saveptr); 
      new = entity_make_monster(monster_make(kind), x, y);
    } else if (!strcmp(kind, "character")) {
      // TODO check pos has not been assigned yet
      game->character->x = nextint(" ", &saveptr);
      game->character->y = nextint("\n", &saveptr);
    } else {
      printf("No such entity kind: [%s]\n", kind);
      exit(1);
    }

    if (new) {
      // new entity needs to be added to the list
      entity_prepend(&head, new);
    }
  } while ((kind = strtok_r(NULL, " ", &saveptr)));
  
  return head;
}

