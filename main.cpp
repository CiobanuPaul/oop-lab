#include <iostream>
#include <cstring>


class Adresa{

    char *strada;
    int nr;
    int codpostal;
    int sector;
    char *localitate;
    char *tara;

public:

    void SetStrada(const char* const strada_){
        delete[] strada;
        strada = new char[strlen(strada_) + 1];
        strcpy(strada, strada_);
    };
    char* GetStrada() const{
        return strada;
    };

    void SetNr(const int nr_){
        nr = nr_;
    }
    int GetNr() const{
        return nr;
    }

    void SetCodpostal(const int codpostal_){
        codpostal = codpostal_;
    };
    int GetCodpostal() const{
        return codpostal;
    }

    void SetSector(const int sector_){
        sector = sector_;
    }
    int GetSector() const{
        return sector;
    }

    void SetLocalitate(const char* const localitate_){
        delete [] localitate;
        localitate = new char[strlen(localitate_) + 1];
        strcpy(localitate, localitate_);
    }
    char *GetLocalitate() const {
        return localitate;
    }

    void SetLTara(const char* const tara_){
        delete [] tara;
        tara = new char[strlen(tara_) + 1];
        strcpy(tara, tara_);
    }
    char *GetTara() const {
        return tara;
    }

    Adresa() {
        strada = new char[7];
        strcpy(strada, "anonim");
    }

    Adresa(const char* const strada_, const int nr_,
           const int codpostal_=0, const int sector_=0,
           const char* const localitate_="Bucuresti",
           const char* const tara_="Romania"){

        delete[] strada;
        strada = new char[strlen(strada_) + 1];
        strcpy(strada, strada_);
        nr = nr_;

        codpostal = codpostal_;
        sector = sector_;
        if(strcmp(localitate_, "Bucuresti") != 0){
            delete [] localitate;
            localitate = new char[strlen(localitate_) + 1];
            strcpy(localitate, localitate_);
        }
        if(strcmp(tara_, "Romania") != 0){
            delete [] tara;
            tara = new char[strlen(tara_) + 1];
            strcpy(tara, tara_);
        }
    }

    Adresa(const Adresa &a){
        delete[] strada;
        strada = new char[strlen(a.strada) + 1];
        strcpy(strada, a.strada);
        nr = a.nr;
        codpostal = a.nr;
        sector = a.sector;
        if(strcmp(a.localitate, "Bucuresti") != 0){
            delete [] localitate;
            localitate = new char[strlen(a.localitate) + 1];
            strcpy(localitate, a.localitate);
        }
        if(strcmp(a.tara, "Romania") != 0){
            delete [] tara;
            tara = new char[strlen(a.tara) + 1];
            strcpy(tara, a.tara);
        }
    }

    ~Adresa(){
        delete [] strada;
        delete [] localitate;
        delete [] tara ;
    }
    friend std::ostream& operator<<(std::ostream& os, const Adresa& a);
};

std::ostream& operator<<(std::ostream& os, const Adresa& a){
        os<<a.strada<<" "<<a.nr<<", ";
        if(a.sector != 0)os<<"sector"<<a.sector;
        if(a.codpostal != 0)os<<", "<<a.codpostal;
        if(strcmp(a.localitate, "Bucuresti")){
            os<<std::endl<<a.localitate;
            if(strcmp(a.tara, "Romania"))
                os<<", "<<a.tara;
        }
}

class Camin;

class Locatar{
    char *nume;
    Camin *camin;
    char *facultate;
    int an;
    int camera;
    bool dosarSocial;

public:
    void SetNume(const char *const nume_) {
        delete[] nume;
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);
    }

    char *GetNume() {
        return nume;
    }

    void SetCamin(Camin &c_) {
        camin = &c_;
    }

    const Camin& GetCamin() const{
        return *camin;
    }

    void SetFacultate(const char *const facultate_) {
        delete[] facultate;
        facultate = new char[strlen(facultate_) + 1];
        strcpy(facultate, facultate_);
    }

    char *GetFacultate() const{
        return facultate;
    }

    void SetAn(const int an_) {
        an = an_;
    }

    int GetAn() const{
        return an;
    }

    void SetCamera(int camera_) {
        camera = camera_;
    }

    int GetCamera() const{
        return camera;
    }

    void SetDosarSocial(const bool dosarSocial_) {
        dosarSocial = dosarSocial_;
    }

    bool GetDosarSocial() const{
        return dosarSocial;
    }

    Locatar(const char* const nume_, Camin &c_,
            const char* const facultate_, const int an_,
            const int camera_, const bool dosarSocial_=0){

        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        camin = &c_;

        facultate = new char[strlen(facultate_) + 1];
        strcpy(facultate, facultate_);

        an = an_;
        camera = camera_;
        dosarSocial = dosarSocial_;
    }
    Locatar(){};
    Locatar(const Locatar &l){
        nume = new char[strlen(l.nume) + 1];
        strcpy(nume, l.nume);

        camin = l.camin;

        facultate = new char[strlen(l.facultate) + 1];
        strcpy(facultate, l.facultate);

        an = l.an;
        camera = l.camera;
        dosarSocial = l.dosarSocial;
    }

    Locatar operator=(const Locatar &l){
        delete [] nume;
        nume = new char[strlen(l.nume) + 1];
        strcpy(nume, l.nume);

        camin = l.camin;

        delete [] facultate;
        facultate = new char[strlen(l.facultate) + 1];
        strcpy(facultate, l.facultate);

        an = l.an;
        camera = l.camera;
        dosarSocial = l.dosarSocial;
    }
    ~Locatar(){
        delete [] nume;
        delete [] facultate;
        delete [] camin;
    }

};

class Camin {
    char *nume;
    char *admin;
    char *corp;
    int capacitate;
    Locatar *locatari;
    int nrloc;  //nr curent de locatari
    int nrcam;  //nr de camere
    int capcam; //nr de locatari intr-o camera
    int taxa;
    Adresa adresa;

public:

    void SetNume(const char *const nume_) {
        delete[] nume;
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);
    };

    char *GetNume() const {
        return nume;
    }

    void SetAdmin(const char *const admin_) {
        delete[] admin;
        admin = new char[strlen(admin_) + 1];
        strcpy(admin, admin_);
    };

    char *GetAdmin() const {
        return admin;
    }

    void SetCorp(const char *const corp_) {
        delete[] corp;
        corp = new char[strlen(corp_) + 1];
        strcpy(corp, corp_);
    };

    char *GetCorp() const {
        return corp;
    }

    void SetCapacitate(const int capacitate_, const bool schimbareCapcam=0) {
        Locatar* aux = locatari;
        locatari = new Locatar[capacitate_];
        int i;
        for(i=0; i < nrloc; i++){
            locatari[i] = aux[i];
        }
//            for(i; i<capacitate_; i++){   //umplem ce a mai ramas cu 0, daca a mai ramas ceva
//                locatari[i] = 0;
//            }
        delete [] aux;
        capacitate = capacitate_;
        //capacitatea s-a schimbat daca s-a schimbat numarul de camere sau capacitatea unei camere
        if(schimbareCapcam==0)   //schimbareCapcam verifica ce tip de schimbare avem
            nrcam = capacitate/capcam + 1;

    }

    int GetCapacitate() const {
        return capacitate;
    }

    void SetNrloc(const int nrloc_) {
        nrloc = nrloc_;
    }

    int GetNrloc() const {
        return nrloc;
    }

    void SetNrcam(const int nrcam_) {
        nrcam = nrcam_;
    }

    int GetNrcam() const {
        return nrcam;
    }

    void SetCapcam(const int capcam_){
        SetCapacitate(capacitate + (capcam_-capcam)*nrcam, 1);
        capcam = capcam_;
    }
    int GetCapcam() const{
        return capcam;
    }
    void SetTaxa(const int taxa_) {
        taxa = taxa_;
    }

    int GetTaxa() const {
        return taxa;
    }

    Camin(){
        nume = new char[7];
        strcpy(nume, "anonim");
        nrloc = 0;
        capacitate = 0;
        nrcam = 0;
        taxa = 0;
        admin = new char[7];
        strcpy(admin, "anonim");
    }
    Camin(const char* const nume_, const char* const corp_,
          const int capacitate_, const int nrcam_, int taxa_,
          const char* const admin_="anonim", const int nrloc_=0,
          const Locatar* const locatari_=new const Locatar){  //s-ar putea sa am probleme cu pointer 'const'

        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        corp = new char[strlen(corp_) + 1];
        strcpy(corp, corp_);

        capacitate = capacitate_;
        nrcam = nrcam_;
        capcam = capacitate/nrcam;
        taxa = taxa_;

        if(strcmp(admin_, "anonim") != 0){
            delete [] admin;
            admin = new char[strlen(admin_)];
            strcpy(admin, admin_);
        }

        if(nrloc_){
            nrloc = nrloc_;
            locatari = new Locatar[nrloc];
            for(int i=0; i<nrloc; i++){
                locatari[i] = locatari_[i];
            }
        }
    }
    Camin(const Camin &c){
        nume = new char[strlen(c.nume) + 1];
        strcpy(nume, c.nume);

        corp = new char[strlen(c.corp) + 1];
        strcpy(corp, c.corp);

        capacitate = c.capacitate;
        nrcam = c.nrcam;
        capcam = capacitate/nrcam;
        taxa = c.taxa;

        if(strcmp(c.admin, "anonim")){
            delete [] admin;
            admin = new char[strlen(c.admin)];
            strcpy(admin, c.admin);
        }
        if(c.nrloc){
            nrloc = c.nrloc;
            locatari = new Locatar[nrloc];
            for(int i=0; i<nrloc; i++)
                locatari[i] = c.locatari[i];
        }
    }
    ~Camin(){
        delete [] nume;
        delete [] admin;
        delete [] corp;
//        delete [] locatari;
    }

    friend std::ostream& operator<<(std::ostream &os, const Camin &c);
};

std::ostream& operator<<(std::ostream &os, const Camin &c){
    os<<"Caminul "<<c.nume<<std::endl;
//    if(strcmp(c.adresa.GetStrada(), "anonim") != 0)
//        os<<"Este situat la adresa:\n"<<c.adresa<<std::endl;
    os<<"Capacitate: "<<c.capacitate<<std::endl;
    os<<"Taxa: "<<c.taxa<<"RON";
//    if(strcmp("anonim", c.admin) != 0){
//        os<<"Administrator: "<<c.admin;
//    }
    os<<"Doriti sa se afiseze datele locatarilor?";

    return os;
}


int main() {
    Camin c1("koga","b",2,1,170);
//    std::cout<<c1;
    return 0;
}
