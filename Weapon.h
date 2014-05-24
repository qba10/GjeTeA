class Weapon{
public:
	int range; // zasięg broni
	int bulletSpeed; // prędkość pocisku
	int fireRate; // szybkostrzelność
	int damage; // ilość obrażeń zadawanych przez 1 pocisk
	int reloadTime; // czas przeładowania
	int maxAmmo; // maksymalna ilość amunicji
	int ammo; // aktualna ilośc amunicji
	bool blastFire; // czy broń zadaje obrażenia obszarowe
	
public:
	void Hit(); // dla zwykłych broni
	void HitByBlast(); // dla broni obszarowych
	int getMaxAmmo();
	int getAmmo();
	void setMaxAmmo(int maxAmmo);
	void decreaseAmmo(); // zmniejsz ilość pocisków po strzale
	void setAmmo(int ammo);
	void setReloadTime(int reloadTime);
	void setDamage(int damage);
	void setFireRate(int fireRate);
	Weapon();
	~Weapon();
};

Weapon::Weapon(){
	this->ammo = maxAmmo;
}

void Weapon::Hit(){

}

void Weapon::HitByBlast(){

}

int Weapon::getMaxAmmo(){
	return maxAmmo;
}

int Weapon::getAmmo(){
	return ammo;
}

void Weapon::setMaxAmmo(int maxAmmo){
	this->maxAmmo = maxAmmo;
}

void Weapon::decreaseAmmo(){
	if(this->ammo > 0)
		this->ammo -= 1;
}

void Weapon::setAmmo(int ammo){
	this->ammo = ammo;
}

void Weapon::setReloadTime(int reloadTime){
	this->reloadTime = reloadTime;
}

void Weapon::setDamage(int damage){
	this->damage = damage;
}

void Weapon::setFireRate(int fireRate){
	this->fireRate = fireRate;
}

