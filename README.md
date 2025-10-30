# 🍽️ Philosophers - Problème des philosophes mangeurs

<img width="196" height="168" alt="image" src="https://github.com/user-attachments/assets/3715d360-5e00-41cc-86c5-e2239a3eac01" />

Le projet Philosophers consiste à simuler le célèbre problème des philosophes mangeurs en C.
Le programme doit gérer plusieurs threads représentant des philosophes, qui alternent entre penser, manger et dormir, tout en partageant des fourchettes et en évitant les deadlocks et la famine.
Ce projet enseigne la programmation concurrente et la synchronisation des ressources partagées.

---

## ✅ Fonctionnalités principales

Création et gestion de threads pour chaque philosophe

Synchronisation via mutex pour éviter les conflits sur les fourchettes

Simulation des actions : manger, penser, dormir

Gestion de la faim et de la mort des philosophes

Support pour différents scénarios et nombre de philosophes

---

## 🔧 Compilation Make

`make`        → compile l’exécutable philosophers  
`make clean`  → supprime les fichiers objets `.o` 
`make fclean` → supprime les fichiers objets et l’exécutable  
`make re`     → recompile entièrement le projet

---

## 🧠 Ce qu’on y apprend

Maîtrise de la programmation multi-thread en C

Gestion des mutex et de la synchronisation pour éviter les deadlocks

Planification et optimisation des ressources partagées

Développement d’un code robuste et normé pour les environnements concurrents

---

## 🏁 Objectif

Simuler un système concurrent en reproduisant le problème des philosophes mangeurs de manière fiable et sécurisée.
L’objectif est de comprendre la programmation parallèle, la gestion de la synchronisation et la prévention des conflits et deadlocks, compétences essentielles pour le développement système et logiciel multi-thread.
