/**
 * @file asteroid.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief The generic asteroid type definition.
 *        Opaque structure. 
 */
typedef struct s_asteroid t_asteroid;

/**
 * @brief The asteroid "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of asteroid location. 
 * @param locY y coordinate of asteroid location. 
 * @param radius asteroid radius size.
 * @param heading asteroid angular heading in radians.
 * @param velocX asteroid x velocity component.
 * @param velocY asteroid y velocity component.
 * @param rotation asteroid rotation.
 * @param color asteroid RGBA color.
 * @return t_asteroid* pointer to the newly created asteroid.
 */
t_asteroid*AsteroidNew(double locX, double locY, double radius, SDL_Color color);

/**
 * @brief The asteroid "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pAsteroid pointer to the asteroid to destroy. 
 * @return t_asteroid* NULL.
 */
t_asteroid*AsteroidDel(t_asteroid*pAsteroid);

/**
 * @brief Performs the graphical drawing of the asteroid.
 * 
 * @param pAsteroid pointer to the asteroid to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_asteroid* pointer to the actual asteroid. 
 */
const t_asteroid*AsteroidDraw(const t_asteroid*pAsteroid, SDL_Renderer*pRenderer);

/**
 * @brief Performs the moving of the asteroid.
 *        Takes care of space area limits over-crossing.
 * 
 * @param pAsteroid pointer to the asteroid to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return t_asteroid* pointer to the actual asteroid. 
 */
t_asteroid*AsteroidMove(t_asteroid*pAsteroid, const SDL_Rect*pSpaceArea);
