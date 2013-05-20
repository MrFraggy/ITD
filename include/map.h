/*!
 *	\file map.h
 *	\author André & Laury
 *	\version 0.1
 *	\date 04/04/13
 *	
 *	\brief Structures de données et fonctions de la carte
 */

#ifndef MAP_H
#define MAP_H

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include <limits.h>

#include "tools.h"
#include "image.h"

/**
 * \struct Map
 * \brief Représente une carte de jeu
 *
 * Comporte une texture, la couleur du noeud et une image ppm
 */
typedef struct _map{
	GLuint tex;
	Node* nodes;
	SDL_Surface* ppm;
	Vector3 camPos;
	Position camDir;
	int drawNodes;
} Map;

/*!
 * \fn extern Map* loadMap(char const* map)
 * \brief Charge une carte de jeu
 *
 * \param map Chemin de la carte que l'on souhaite charger
  * \return Pointeur vers la carte si le chargement a réussi, NULL sinon.
 */
extern Map* loadMap(char const* map);

/*!
 * \fn extern void drawNode(Node* n, Vector3 camPos)
 * \brief Dessine un noeud sur la carte
 *
 * \param n Noeud que l'on souhaite dessiner
 */
extern void drawNode(Node* n, Vector3 camPos);

/*!
 * \fn extern void drawMap(Map* m)
 * \brief Dessine une carte de jeu
 *
 * \param m Carte que l'on souhaite dessiner
 */
extern void drawMap(Map* m);

/*!
 * \fn extern void deleteMap(Map* m)
 * \brief Supprime une carte de jeu
 *
 * \param m Carte que l'on souhaite supprimer
 */
extern void deleteMap(Map* m);

/*!
 * \fn extern int collideWithMap(Map* m, Position p, Position s)
 * \brief Vérifie si une tour de coordonnée p et taille s peut être placée
 *
 * \param m Carte du jeu
 * \param p position de la tour
 * \param s taille de la tour
 *
 * \return 1 si la tour est en collision avec la map, 0 sinon.
 */
extern int collideWithMap(Map* m, Position p, Position s, Vector3 camPos);

extern void updateMap(Map* m);

extern void addCameraDirection(Map* m, Position pos);

extern void moveCamera(Map* m, Position pos);

#endif
