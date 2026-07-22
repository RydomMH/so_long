# 🕹️ So Long

<p align="center">
  <img src="https://img.shields.io/badge/42-So__Long-blue" alt="42 Project">
  <img src="https://img.shields.io/badge/Norm-100%2F100-success" alt="Norm">
  <img src="https://img.shields.io/badge/Language-C-orange" alt="Language">
</p>

## 📖 À propos

**So Long** est un projet de l'école 42 ayant pour but de créer un petit jeu 2D en C à l'aide de la **MinilibX**. Le joueur doit se déplacer sur une carte, collecter tous les objets présents, puis atteindre la sortie en effectuant le moins de mouvements possible.

Ce projet est une introduction à la programmation graphique, à la gestion des sprites et au parsing de fichiers.


## ⚙️ Fonctionnalités

- 🗺️ Chargement d'une carte personnalisée (`.ber`)
- ✅ Vérification de la validité de la carte (murs, chemin praticable, un seul joueur, autant de sorties que nécessaire, etc.)
- 🧍 Déplacement du joueur avec sprites animés
- 🪙 Système de collecte d'objets
- 🚪 Sortie accessible uniquement après collecte de tous les objets
- 🔢 Compteur de mouvements affiché dans le titre de la fenêtre
- ❌ Gestion propre de la fermeture (croix, ESC) sans fuite mémoire
- 🎁 Animation des sprites *(si bonus réalisé)*

## 🛠️ Compilation

```bash
git clone git@github.com:RydomMH/so_long.git
cd So_long
make
```

## ▶️ Utilisation

```bash
./so_long maps/map.ber
```

Contrôles :

| Touche | Action |
|--------|--------|
| `W` `A` `S` `D` ou flèches | Déplacement |
| `ESC` | Quitter le jeu |
| Croix de la fenêtre | Quitter proprement |

## 🗂️ Règles de la carte (.ber)

- Carte rectangulaire, entourée de murs (`1`)
- Un seul joueur (`P`)
- Au moins une collectible (`C`)
- Une sortie (`E`)
- Un chemin valide doit exister entre le joueur, toutes les collectibles et la sortie

Exemple :

1111111111
100C0000C1
10111011P1
1000010001
100C000001
1E11111101
1111111111


## 🧠 Ce que ce projet m'a appris

- Les bases de la programmation graphique avec la MinilibX
- La gestion des textures/sprites (fichiers `.xpm`)
- Le parsing rigoureux d'un fichier et la validation de carte (algorithme de flood fill)
- La gestion de la mémoire (aucune fuite, `close()` propre)
- La structuration d'un projet C avec une bonne architecture

## 👤 Auteur

- **[Ton pseudo 42]** - [Profil 42](https://profile.intra.42.fr/users/<ton_pseudo>)

## 📄 Licence

Projet réalisé dans le cadre du cursus de l'école 42.
