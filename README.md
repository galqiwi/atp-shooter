# atp-shooter
Псевдотрёхмерный шутер на C++

##инструкции по сборке
Для того, чтобы собрать этот проект, надо поставить библиотеку [SFML](sfml-dev.org).

Поставить SFML на ubuntu можно через apt.
```bash
sudo apt install libsfml-dev -y
```
[Туториал, если у вас не мак.](https://www.sfml-dev.org/tutorials/2.5/)

После установки SFML проект можно собрать с помощью cmake.
```bash
mkdir build
cd build
cmake .. && make
```
бинарный файл устанавливается в папку bin.

##инструкции по установке
В папке release

## [структура проекта](STRUCTURE.md)
