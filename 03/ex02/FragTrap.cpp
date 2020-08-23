#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->name = "default";
	std::cout << "FR4G-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 100;
	this->maxEP = 100;
	this->lv = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "FR4G-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 100;
	this->maxEP = 100;
	this->lv = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap(other)
{
	std::cout << "FR4G-TP <" << this->name << "> is copied" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP <" << this->name << "> is deleted" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	this->HP = other.HP;
	this->maxHP = other.maxHP;
	this->EP = other.EP;
	this->maxEP =other.maxEP;
	this->lv = other.lv;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
	return (*this);
}


void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device	rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(1, 5);

	if (this->EP < 25)
	{
		std::cout << "FR4G-TP " << this->name
				<< " is out of energy" << std::endl;
		return ;
	}
	this->EP -= 25;
	switch (dis(gen))
	{
		case 1:
			minionTrap(target);
			break ;
		case 2:
			meleeAttack(target);
			break ;
		case 3:
			rangedAttack(target);
			break ;
		case 4:
			rubberDucky(target);
			break ;
		case 5:
			senselessSacrifice(target);
			break ;
	}
}

void	FragTrap::minionTrap(std::string const &target)
{
	std::cout << "\"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!\"" << std::endl;
		std::cout << "FR4G-TP <" << this->name << "> attacks <" << target
	<< "> causing " << 10
	<< " points of damage!" << std::endl;
}

void	FragTrap::rubberDucky(std::string const &target)
{
	std::cout << "\"I'm a superball!\"" << std::endl;
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target
	<< "> causing " << 10
	<< " points of damage!" << std::endl;
}

void	FragTrap::senselessSacrifice(std::string const &target)
{
	std::cout << "\"The robot is dead, long live the robot!\"" << std::endl;
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target
	<< "> causing " << 10
	<< " points of damage!" << std::endl;
}