/**
 * @file sceneDefines.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define SCENE_LEVEL_SHOW_TIMEOUT            (7.0)                          /* level text displaying time in seconds */
#define SCENE_COLOR_BKGND    				((SDL_Color){10,10,30,255})		/* RGBA color of scene background */
#define SCENE_COLOR_SCORE                   ((SDL_Color){10,200,30,255})	/* RGBA color of text score */

#define SCENE_SHIP_INITIAL_COUNT    		(5)								/* number of ships at starting game */
#define SCENE_SHIP_SIZE             		(50)							/* engaged ship size*/
#define SCENE_SHIP_ENGAGED_COLOR    		(SDL_Color){255,255,255,255}	/* engaged ship RGBA color*/
#define SCENE_SHIP_LIVES_COLOR      		(SDL_Color){100,200,80,255}		/* live ships RGBA color*/
#define SCENE_SHIP_THRUST_COLOR     		(SDL_Color){252,127,3,255}		/* engaged ship thrust RGBA color */

#define SCENE_ASTEROID_NB_INITIAL			(15)							/* number of asteroids at starting game level 0*/
#define SCENE_ASTEROID_CLEARING_ZONE_RATIO	(5.0)							/* ratio to ship size of asteroids cleared area around the engaged one */
#define SCENE_ASTEROID_SIZE_MAX				(150)							/* maximum size of generated asteroids */
#define SCENE_ASTEROID_SIZE_MIN				(20)							/* minimum size of generated asteroids */
#define SCENE_ASTEROID_RGB_MAX				(150)							/* maximum asteroid RGB component value */
#define SCENE_ASTEROID_RGB_MIN				(80)							/* minimum asteroid RGB component value */

#define SCENE_ASTEROID_SCORE_POINT_LARGE    (10)							/* score point for destroying a large asteroid */
#define SCENE_ASTEROID_SCORE_POINT_MEDIUM   (20)							/* score point for destroying a medium asteroid */
#define SCENE_ASTEROID_SCORE_POINT_SMALL    (50)							/* score point for destroying a small asteroid */



