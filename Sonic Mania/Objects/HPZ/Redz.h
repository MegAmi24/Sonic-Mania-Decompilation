#ifndef OBJ_REDZ_H
#define OBJ_REDZ_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    Hitbox hitboxBadnik;
    Hitbox attackbox;
    Hitbox hitboxFlame;
    Hitbox hitboxRange;
    uint16 aniFrames;
    uint16 sfxFlame;
} ObjectRedz;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    Vector2 startPos;
    uint8 startDir;
    uint16 timer2;
    uint16 timer;
    Animator animator;
} EntityRedz;

// Object Entity
extern ObjectRedz *Redz;

// Standard Entity Events
void Redz_Update(void);
void Redz_LateUpdate(void);
void Redz_StaticUpdate(void);
void Redz_Draw(void);
void Redz_Create(void* data);
void Redz_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void Redz_EditorDraw(void);
void Redz_EditorLoad(void);
#endif
void Redz_Serialize(void);

// Extra Entity Functions
void Redz_DebugSpawn(void);
void Redz_DebugDraw(void);

void Redz_HandlePlayerInteractions(void);

void Redz_State_Setup(void);
void Redz_State_Walk(void);
void Redz_State_Turn(void);
void Redz_State_PrepareAttack(void);
void Redz_State_Attack(void);
void Redz_Flame_Setup(void);
void Redz_Flame_State(void);

#endif //!OBJ_REDZ_H
