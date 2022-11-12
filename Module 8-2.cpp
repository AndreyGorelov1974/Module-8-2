﻿/*Задание 2. Immolate Improved!
Что нужно сделать
Мы придумываем фэнтезийную онлайн-игру в жанре RPG. В орка стреляют огненными шарами разной степени мощности, но у него есть очки здоровья и показатель сопротивляемости магии.
Очки здоровья, сопротивляемость магии и мощность огненного шара — это вещественные числа от нуля до единицы включительно.
Чем больше мощность, тем больше урон здоровью, но чем больше сопротивляемость магии, тем урон меньше. Например, если сопротивляемость равна нулю (0%), то будет нанесён урон, равный мощности огненного шара.
Если сопротивляемость равна единице (100%), урон будет равен нулю, даже если мощность заклинания максимальна.

Напишите программу, в которой пользователь сначала задаёт количество здоровья и сопротивляемость магии орка, а после стреляет в него огненными шарами разной мощности, пока орк не погибнет.
Мощность удара вводится с клавиатуры с каждым выстрелом. После каждого заклинания программа выводит на экран итоговый урон от удара и оставшиеся очки здоровья орка.
Показатель сопротивляемости магии не изменяется при попадании. Обеспечьте контроль ввода.

Рекомендации по выполнению
Для решения использовать цикл while.

Что оценивается
Все величины должны измеряться в одной шкале — от 0 до 1.

Мощность удара считается с учётом сопротивляемости.*/

#include <iostream>
#include <cmath>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите очки здоровья орка (вещественное число от 0 до 1): ";
	float orcHealth;
	std::cin >> orcHealth;
	while (orcHealth < 0 || orcHealth > 1) {
		std::cout << "Число должно быть в диапазон от 0 до 1. Введите снова: ";
		std::cin >> orcHealth;
	}

	std::cout << "Введите сопротивляемость магии (вещественное число от 0 до 1): ";
	float magicResistance;
	std::cin >> magicResistance;
	while (magicResistance < 0 || magicResistance > 1) {
		std::cout << "Число должно быть в диапазон от 0 до 1. Введите снова: ";
		std::cin >> magicResistance;
	}


	while (orcHealth > 0) {

		std::cout << "Введите мощность огненного шара (вещественное число от 0 до 1): ";
		float fireballPower;
		std::cin >> fireballPower;
		while (fireballPower < 0 || fireballPower > 1) {
			std::cout << "Число должно быть в диапазон от 0 до 1. Введите снова: ";
			std::cin >> fireballPower;
		} 

		float magicDamage = fireballPower * (1 - magicResistance);
		orcHealth -= magicDamage;

		if (orcHealth > 0) std::cout << "Орку нанесён урон " << magicDamage << ", у него осталось " << orcHealth << " здоровья." << std::endl;
	 } 

	std::cout << "Орк погиб!" << std::endl;
}
