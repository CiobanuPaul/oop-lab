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

    Adresa() = default;

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
        delete [] tara;
    }
};

class Camin {
    char *nume;
    char *admin;
    char *corp;
    int capacitate;
    Locatari *locatari;
    int nrloc;  //nr curent de locatari
    int nrcam;  //nr de camere
    int capcam; //nr de locatari intr-o camera
    int taxa;
    Adresa adresa;
    {
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

        void SetCapacitate(const int capacitate_ const bool schimbareCapcam=0) {
            Locatari* aux = locatari;
            locatari = new Locatari[capacitate_];
            int i;
            for(i=0; i < nrloc; i++){
                locatari[i] = aux[i];
            }
            for(i; i<capacitate_; i++){   //umplem ce a mai ramas cu 0, daca a mai ramas ceva
                locatari[i] = 0;
            }
            delete [] aux;
            capacitate = capacitate_;
            //capacitatea s-a schimbat daca s-a schimbat numarul de camere sau capacitatea unei camere
            if(schimbareCapcam=0)   //schimbareCapcam verifica ce tip de schimbare avem
                nrcam = capacitate/capcam + 1;

        }

        int GetCapacitate() const {
            return capacitate;
        }

        void SetLocatari

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
            SetCapacitate(capacitate + (capcam_-capcam)*nrcam, schimbareCapcam=1);
            capcam = capcam_;
        }
        int GetCapcam() const{
            return capcam
        }
        void SetTaxa(const int taxa_) {
            taxa = taxa_;
        }

        int GetTaxa() const {
            return taxa;
        }
    }

    Camin(){
        nrloc = 0;
        admin = new char[1];
    }
    Camin(const char* const nume_, const char* const corp_,
          const int capacitate_, const int nrcam_, int taxa_,
          const char* const admin_="", cont int nrloc_=0){

        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        corp = new char[strlen(corp_) + 1];
        strcpy(corp, corp_);

        capacitate = capacitate_;
        nrcam = nrcam_;
        capcam = capacitate/nrcam;
        taxa = taxa_;

        if(strcmp(admin_, "")){
            delete [] admin;
            admin = new char[strlen(admin_)];
            strcpy(admin, admin_);
        }

        if(nrloc_){              //as putea pune vectorul ca parametru
            nrloc = nrloc_;
            std :: cout<<"Introduceti locatarii:"<<endl;
            for(int i=0; i<nrloc; i++)
                std :: cin>>locatari[i];
        }
    }
    Camin(const Camin &c){       //de inlocuit *_ cu c.*
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        corp = new char[strlen(corp_) + 1];
        strcpy(corp, corp_);

        capacitate = capacitate_;
        nrcam = nrcam_;
        capcam = capacitate/nrcam;
        taxa = taxa_;

        if(strcmp(admin_, "")){
            delete [] admin;
            admin = new char[strlen(admin_)];
            strcpy(admin, admin_);
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
