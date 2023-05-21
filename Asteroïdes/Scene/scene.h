/**
 * @file scene.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief The generic scene type definition.
 *        Opaque structure.
 */
typedef struct s_scene t_scene;

/**
 * @brief The scene "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param iWidth horizontal size of the scene.
 * @param iHeight vertical size of the scene.
 * @param pRenderer pointer to the window renderer for graphical drawings.
 * @param pFont pointer to the character font.
 * @return t_scene* pointer to the newly created scene.
 */
t_scene*SceneNew(int iWidth, int iHeight, SDL_Renderer*pRenderer, TTF_Font*pFont);

/**
 * @brief The scene "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pScene pointer to the scene to destroy. 
 * @return t_scene* NULL;
 */
t_scene*SceneDel(t_scene*pScene);

/**
 * @brief Performs all drawings, scene and all contained graphical objects.
 * 
 * @param pScene pointer to the scene to draw.
 * @return t_scene* pointer to the scene himself.
 */
t_scene*SceneDraw(t_scene*pScene);

/**
 * @brief Performs all animations, scene and all contained graphical objects.
 * 
 * @param pScene pointer to the scene to animate.
 * @return t_scene* pointer to the scene himself.
 */
t_scene*SceneAnimate(t_scene*pScene);

/**
 * @brief Takes care of key down events from app.
 * 
 * @param pScene pointer to the scene responsible of key down events.
 * @param pEvent pointer to the keyboad event.
 * @return t_scene* pointer the actual scene object.
 */
t_scene*SceneKeydown(t_scene*pScene, SDL_KeyboardEvent*pEvent);

/**
 * @brief Takes care of key up events from app.
 * 
 * @param pScene pointer to the scene responsible of key up events.
 * @param pEvent pointer to the keyboad event.
 * @return t_scene* pointer the actual scene object.
 */
t_scene*SceneKeyup(t_scene*pScene, SDL_KeyboardEvent*pEvent);


