/**
 * @file entity.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief defines the commons fields of entities family
 */
#define _ENTITY_COMMON_FIELDS_ \
	double 		m_locX;		    /* entity x coordinate */\
	double 		m_locY;		    /* entity y coordinate */\
	double 		m_radius;	    /* entity radius */\
	double 		m_velocX;	    /* entity x velocity component */\
	double 		m_velocY;	    /* entity y velocity component */\
	double 		m_heading;	    /* entity angular heading in radians */\
	double		m_rotation;	    /* entity rotation step in radians */\
    SDL_Color   m_color;        /* entity RGBA color */\
    SDL_Point  *m_pVertices;    /* entity pointer to vertices array */\
    size_t		m_szVertices;	/* entity number of polygon vertices */

/**
 * @brief defines all kinds of collisions
 */
typedef enum e_collision{
    COLLISON_NONE   = 0,
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_TOP,
    COLLISION_BOT,
    COLLISION_OTHER
}t_collision;

/**
 * @brief The generic entity type definition.
 *        Opaque structure. 
 */
typedef struct s_entity t_entity;

/**
 * @brief The entity "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX entity x coordinate.
 * @param locY entity y coordinate.
 * @param radius entity radius.
 * @param heading entity angular heading in radians.
 * @param velocX entity x velocity component.
 * @param velocY entity y velocity component.
 * @param rotation entity rotation step in radians.
 * @param color entity RGBA color.
 * @return t_entity* pointer to the newly created entity.
 */
t_entity*EntityNew(
    double locX, double locY, 
    double radius, 
    double heading, 
    double velocX, double velocY, 
    double rotation,
    SDL_Color color);

/**
 * @brief The entity "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pEntity pointer to the entity to destroy.
 * @return t_entity* NULL.
 */
t_entity*EntityDel(t_entity*pEntity);

/**
 * @brief Drawing the entity.
 * 
 * @param pEntity pointer to the entity to draw.
 * @param pRenderer pointer to the renderer to draw in.
 * @return t_entity* NULL.
 */
t_entity*EntityDraw(const t_entity*pEntity, SDL_Renderer*pRenderer);

/**
 * @brief Moving the entity into the space area.
 * 
 * @param pEntity pointer to the entity to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return int 0 in case of no over-crossing,
 *             non null, otherwise.
 */
t_collision EntityMove(t_entity*pEntity, const SDL_Rect*pSpaceArea);

/**
 * @brief Performs a collision check between two entities. 
 * 
 * @param pEntityA pointer to the first entity involved in collision ckecking.
 * @param pEntityB pointer to the second entity involved in collision ckecking.
 * @return t_collision null value in case of no collision detected,
 *                     non null otherwise.
 */
t_collision EntityHasCollision(const t_entity*pEntityA, const t_entity*pEntityB);

/**
 * @brief Returns the entity x location coordinate.
 * 
 * @param pEntity pointer to the entity.
 * @return double x location coordinate.
 */
double EntityGetLocX(const t_entity*pEntity);

/**
 * @brief Returns the entity y location coordinate.
 * 
 * @param pEntity pointer to the entity.
 * @return double y location coordinate.
 */
double EntityGetLocY(const t_entity*pEntity);

/**
 * @brief Returns the entity radius.
 * 
 * @param pEntity pointer to the entity.
 * @return double radius.
 */
double EntityGetRadius(const t_entity*pEntity);

/**
 * @brief Returns the entity RGBA color.
 * 
 * @param pEntity pointer to the entity.
 * @return SDL_Color RGBA color.
 */
SDL_Color EntityGetColor(const t_entity*pEntity);

/**
 * @brief Determines the distance from entity to the designed point.
 * 
 * @param pEntity pointer to the entity.
 * @param pPoint pointer to the point.
 * @return double distance value.
 */
double EntityDistanceToPoint(const t_entity*pEntity, const SDL_Point*pPoint);
