# actividad1-paralela

Se realiza ejercicio de multiplicacion de matrices en C de manera secuencial e implementación OMP. Se adjuntan  los archivos .cpp y los ejecutables generados al compilar.

Se realizan distintas pruebas con distintos valores de tamaño de matriz y se obtienen los siguientes resultados:

Para tamaño de matriz = 50, se obtienen tiempos muy similares al implementar programacion paralela.

Secuencial:
![00e17e25-bb40-4fbc-ae6d-2beeabf47704](https://github.com/davidvasquez02/actividad1-paralela/assets/70860023/7c5d356e-ecfa-4ba7-bbe4-f9656b62e5ed)
Paralela:
![bd47058a-387d-42e4-b70d-ec77438830df](https://github.com/davidvasquez02/actividad1-paralela/assets/70860023/56f4e8ae-9a27-4d13-af26-ef05b9663b93)

Podemos inferir que para valores pequeños no es tan significativa la mejora de la computacion paralela.

Para tamaño de matriz = 500, se obtienen resultados de tiempo muy distantes donde se evidencia que el algoritmo con programacion paralela presenta mucho mejor tiempo de respuesta que el secuencial.

Secuencial:
![a845bbe9-7b20-4895-b057-e060def0f185](https://github.com/davidvasquez02/actividad1-paralela/assets/70860023/792686f7-a695-49f9-a532-797f7946bec6)

Paralela:

![a62784b9-be31-419c-bd97-fd93c46032b6](https://github.com/davidvasquez02/actividad1-paralela/assets/70860023/0f1ade9e-8f56-4026-bce4-163c613e7187)

Para este caso se evidencia que la programacion paralela es de uitilidad al resolver problemas de este estilo con tamanos de matriz bastante grandes.
