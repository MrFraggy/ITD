/*!
 *	\file monster.h
 *	\author André & Laury
 *	\version 0.1
 *	\date 04/04/13
 *	
 *	\brief Structures de données et fonctions des monstres
 */

#ifndef MONSTER_H
#define MONSTER_H

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include "tools.h"

/*!
 * \enum TYPE_MONSTER
 * \brief Tous les types de Monstres
 */
typedef enum{
	NORMAL,
	FAST,
	SLOW,
	FLYER
} TYPE_MONSTER;

extern const int Normal;
extern const int Fast;
extern const int Slow;
extern const int Flyer;


/**
 * \struct Monster
 * \brief Représente un monstre ennemi
 *
 * Comporte des points de vie, une texture, un type, des coordonnées, une direction et le temps écoulé depuis le dernier mouvement
 */
typedef struct _monster{
	int life;
	int life_max;
	GLuint tex;
	TYPE_MONSTER type;
	Position coord;
	Node* direction;
	GLint msecSinceLastMvt;
} Monster;

/*!
 * \fn extern Monster* createMonster(TYPE_MONSTER type, Node* start)
 * \brief Création d'un monstre
 *
 * \param type Type du monstre à créer
 * \param start Noeud de départ du monstre
 * \return Pointeur vers le monstre si la création a réussi, NULL sinon.
 */
extern Monster* createMonster(TYPE_MONSTER type, Node* start, GLint timer);

/*!
 * \fn extern void drawMonster(Monster* m)
 * \brief Dessine un monstre
 *
 * \param m Pointeur vers le monstre à créer
 */
extern void drawMonster(Monster* m);

/*!
 * \fn extern void updateMonster(Monster* m, GLuint elapsedTime)
 * \brief Met à jour un monstre
 *
 * \param m Pointeur vers le monstre à mettre à jour
 * \param elapsedTime Temps écoulé
 */
extern void updateMonster(Monster* m, GLuint elapsedTime);

/*!
 * \fn extern int hasFinishedMonster(Monster* m)
 * \brief Détermine si un monstre a terminé le parcours
 *
 * \param m Pointeur vers le monstre
 */
extern int hasFinishedMonster(Monster* m);

/*!
 * \fn extern void deleteMonster(Monster* m)
 * \brief Supprime un monstre
 *
 * \param m Pointeur vers le monstre à supprimer
 */
extern void deleteMonster(Monster* m);

extern int isDead(Monster* m);

#endif
