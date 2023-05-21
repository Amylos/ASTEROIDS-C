/**
 * @file entityDefines.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define ENTITY_SHIP_THRUST                  (20.0)      /* ship acceleration in pixels per second per second */
#define ENTITY_SHIP_SPACE_FRICTION          (.7)        /* friction coefficient of space 0.0: no friction 1.0: lot of friction */
#define ENTITY_SHIP_TURN_SPEED              (360)       /* angular ship speed in degrees per second */
#define ENTITY_SHIP_NOISE_RATIO		        (1.0)       /* radius ratio for ship noise vertex position */
#define ENTITY_SHIP_WINGS_RATIO		        (0.85)      /* radius ratio for ship wings vertex position */
#define ENTITY_SHIP_REAR_RATIO		        (0.33)      /* radius ratio for ship rear vertex position */
#define ENTITY_SHIP_THRUST_RATIO            (0.80)      /* drawing thrust ratio to ship radius */

#define ENTITY_LASER_SPEED                  (500)       /* laser speed in pixels per second */
#define ENTITY_LASER_SIZE				    (4)			/* laser size, drawing as a square shape */
#define ENTITY_LASER_MAX_DIST			    (.040)		/* laser max distance range in fraction of the screen width */
#define ENTITY_LASER_MAX_NUM			    (10)		/* maximum number of lasers on screen at once */
#define ENTITY_LASER_COLOR				    (SDL_Color){255,50,50,255}

#define ENTITY_ASTEROIDS_SPEED              (20)        /* asteroids speed max in pixels per second */
#define ENTITY_ASTEROIDS_ROT_SPEED_MAX      (45)        /* asteroids angular speed max in degrees per second */
#define ENTITY_ASTEROIDS_VERTICES_NUM_MAX   (16)		/* asteroids vertices average number */
#define ENTITY_ASTEROIDS_VERTICES_NUM_MIN   (8)
#define ENTITY_ASTEROIDS_JAGGER             (5)		/* asteroids vertices radial position random variation */

#define ENTITY_EXPLOSION_STAR_TTL           (0.250)     /* explosions display time in seconds */
#define ENTITY_EXPLOSION_STAR_RADIUS        (25)      	/* explosions shape radius */
#define ENTITY_EXPLOSION_STAR_NB_BRANCHES   (12)		/* explosions star branches average number */
#define ENTITY_EXPLOSION_STAR_BRANCH_JAGGER (.5)		/* explosions vertices radial position random variation */
