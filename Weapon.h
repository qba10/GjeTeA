namespace SSJ{
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
}
