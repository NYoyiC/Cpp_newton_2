# Análisis de Radiación de Cuerpo Negro usando la Ley de Planck y el Método de Newton-Raphson

Este proyecto contiene un código en C++ que implementa el método de Newton-Raphson para encontrar la frecuencia \( \nu \) que maximiza la intensidad de la radiación de cuerpo negro según la ley de Planck a una temperatura constante de \(3.5 \times 10^3\) K.

## Descripción

La ley de Planck describe la distribución espectral de la radiación electromagnética emitida por un cuerpo negro en equilibrio térmico a una temperatura específica \( T \). Este proyecto incluye:

1. **Implementación de la Ley de Planck**: Cálculo de la derivada de la intensidad espectral de la radiación \( B'(\nu) \).
2. **Derivada de la Función \( B'(\nu) \)**: Cálculo de la segunda derivada \( B''(\nu) \) para aplicar el método de Newton-Raphson.
3. **Método de Newton-Raphson**: Aplicación iterativa para encontrar la frecuencia \( \nu \) que maximiza \( B(\nu) \).

## Uso

Para ejecutar el código, sigue estos pasos:

### Compilación

Asegúrate de tener un compilador C++ instalado. Puedes usar `g++`:

```sh
g++ -o planck_newton planck_newton.cpp
