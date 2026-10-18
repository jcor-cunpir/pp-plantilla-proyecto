# Plantilla del proyecto · Proyectos de Programación (CUNEF)

![CI](https://github.com/jcor-cunpir/pp-plantilla-proyecto/actions/workflows/ci.yml/badge.svg)

Punto de partida para el proyecto de la asignatura: estructura `include/` + `src/` + `tests/`,
`CMakeLists.txt` listo, **tests con GoogleTest** y **pipeline de CI** con GitHub Actions
(lo que pide la Entrega 2).

> **Cambiad el badge de arriba** para que apunte a vuestro repositorio: sustituid
> `jcor-cunpir/pp-plantilla-proyecto` por `vuestro-usuario/vuestro-repositorio`.

## 1. Crear el repositorio del grupo (lo hace UNA persona)

1. Botón verde **Use this template** → **Create a new repository**.
2. Nombre del proyecto sin espacios (p. ej. `gestor-biblioteca`), **Private**, **Create repository**.
3. **Settings → Collaborators → Add people**: añadid a todos los miembros del grupo y al profesor (usuario de GitHub `jcor-cunpir`).

## 2. Descargar, compilar y ejecutar (cada miembro)

| | Windows (PowerShell) | Mac (Terminal) |
| --- | --- | --- |
| Descargar | `git clone https://github.com/vuestro-usuario/vuestro-repo.git` | igual |
| Entrar en la carpeta | `cd vuestro-repo` | igual |
| Configurar (1.ª vez; descarga GoogleTest) | `cmake -S . -B build -G Ninja` | `cmake -S . -B build` |
| Compilar | `cmake --build build` | `cmake --build build` |
| Ejecutar el programa | `.\build\gestor.exe` | `./build/gestor` |
| Pasar los tests | `cd build`, `ctest --output-on-failure` y `cd ..` para volver | igual |
| Ver el detalle de los tests | `.\build\tests_gestor.exe` | `./build/tests_gestor` |

## 3. Dónde va cada cosa

```
CMakeLists.txt         <- añadid aquí cada .cpp nuevo (lista FUENTES) y cada fichero de tests
include/               <- vuestras cabeceras .hpp
src/main.cpp           <- el programa principal (menú del gestor)
src/*.cpp              <- la implementación de vuestras clases
tests/test_*.cpp       <- tests con GoogleTest (la Entrega 2 pide al menos 5 que pasen en el pipeline)
.github/workflows/     <- el pipeline de CI: compila y pasa los tests en cada push
```

La clase `Habitacion` (con sus tests) es **solo un ejemplo**. Cuando tengáis vuestras clases:

1. Cambiad `src/main.cpp` para que use vuestras clases en lugar de `Habitacion` (quitad también su `#include`).
2. Borrad `include/habitacion.hpp`, `src/habitacion.cpp` y `tests/test_habitacion.cpp`.
3. Quitad sus líneas del `CMakeLists.txt` (en `FUENTES` y en `tests_gestor`).

## 4. El pipeline (CI)

Cada `git push` a `main` o `develop`, y cada Pull Request a `main`, lanza el workflow **CI** (pestaña **Actions**):
compila el proyecto en una máquina Linux limpia y ejecuta `ctest`. Si sale en **rojo**, haced clic en la ejecución para ver qué paso ha fallado.
**El pipeline tiene que estar en verde en el último commit de `main` el día de la Entrega 2.**

## 5. Errores frecuentes

| Mensaje | Arreglo |
| --- | --- |
| `undefined reference to ...` | Falta el `.cpp` en la lista `FUENTES` del `CMakeLists.txt` |
| `unable to find a build program corresponding to "Ninja"` (Windows) | En la terminal MSYS2: `pacman -S --needed mingw-w64-x86_64-ninja` |
| `Does not match the generator used previously` | Borrad la carpeta `build` y volved a configurar |
| Falla al descargar GoogleTest | Hace falta conexión a internet la primera vez que se configura |
