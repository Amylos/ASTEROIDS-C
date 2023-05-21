/**
 * @file laser.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief The generic laser type definition.
 *        Opaque structure. 
 */
typedef struct s_laser t_laser;

/**
 * @brief The laser "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of laser location. 
 * @param locY y coordinate of laser location. 
 * @param radius laser radius size.
 * @param heading laser angular heading in radians.
 * @param velocX laser x velocity component.
 * @param velocY laser y velocity component.
 * @param color laser RGBA color.
 * @return t_laser* pointer to the newly created laser.
 */
t_laser*LaserNew(double locX, double locY, double radius, double heading, double velocX, double velocY, SDL_Color color);

/**
 * @brief The laser "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pLaser pointer to the laser to destroy. 
 * @return t_laser* NULL.
 */
t_laser*LaserDel(t_laser*pLaser);

/**
 * @brief Performs the graphical drawing of the laser.
 * 
 * @param pLaser pointer to the laser to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_laser* NULL. 
 */
const t_laser*LaserDraw(const t_laser*pLaser, SDL_Renderer*pRenderer);

/**
 * @brief Performs the moving of the laser.
 *        Takes care of space area limits over-crossing.
 * 
 * @param pLaser pointer to the laser to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return t_laser*  depends on condition. 
 */
t_laser*LaserMove(t_laser*pLaser, const SDL_Rect*pSpaceArea);