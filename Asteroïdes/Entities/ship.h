/**
 * @file ship.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief ship turning definition
 */
typedef enum e_turning{
	TURN_NONE = 0,
	TURN_LEFT,
	TURN_RIGHT
}t_turning;

/**
 * @brief The generic ship type definition.
 *        Opaque structure. 
 */
typedef struct s_ship t_ship;

/**
 * @brief The ship "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of ship location. 
 * @param locY y coordinate of ship location. 
 * @param radius ship radius size.
 * @param heading ship angular heading in radians.
 * @param colorShip ship RGBA color.
 * @param colorThrust ship thrust RGBA color.
 * @return t_ship* pointer to the newly created ship.
 */
t_ship*ShipNew(double locX, double locY, double radius, double heading, SDL_Color colorShip, SDL_Color colorThrust);

/**
 * @brief The ship "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pShip pointer to the ship to destroy. 
 * @return t_ship* NULL.
 */
t_ship*ShipDel(t_ship*pShip);

/**
 * @brief Performs the graphical drawing of the ship.
 * 
 * @param pShip pointer to the ship to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_ship* NULL. 
 */
const t_ship*ShipDraw(const t_ship*pShip, SDL_Renderer*pRenderer);

/**
 * @brief Performs the moving of the ship.
 *        Takes care of space area limits over-crossing.
 * 
 * @param pShip pointer to the ship to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return t_ship* pointer to the actual ship. 
 */




t_ship*ShipMove(t_ship*pShip, const SDL_Rect*pSpaceArea);

/**
 * @brief Enabling/Disabling the ship thrusting.
 * 
 * @param pShip pointer to the ship to thrust enabling.
 * @param enable the enabling state
 * @return t_ship* pointer to the actual ship.
 */
t_ship*ShipThrusting(t_ship*pShip, int enable);

/**
 * @brief Setting the ship turning.
 * 
 * @param pShip pointer to the ship to set turning.
 * @param turning turning mode.
 * @return t_ship* pointer to the actual ship.
 */
t_ship*ShipTurning(t_ship*pShip, t_turning turning);

/**
 * @brief Performs ship engagment.
 * 
 * @param pShip pointer to the ship to engage.
 * @param locX x coordinate where to engage.
 * @param locY y coordinate where to engage.
 * @param radius new ship radius size. 
 * @param heading new ship heading.
 * @param color engaged ship color.
 * @return t_ship* pointer to the current engaged ship.
 */
t_ship*ShipEngage(t_ship*pShip, double locX, double locY, double radius, double heading, SDL_Color color);

/**
 * @brief Performs a laser shoot.
 * 
 * @param pShip pointer to the ship who makes a laser shoot.
 * @return t_laser* pointer to the newly created laser.
 */
t_laser*ShipLaserShoot(const t_ship*pShip);
