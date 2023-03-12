#include <iostream>
#include <fstream>
#include <cstring>
std::ifstream fin("tastatura.txt");


int nranonim = 5000;

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

    void SetTara(const char* const tara_){
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

        nr = 0;
        codpostal = 0;
        sector = 0;

        localitate = new char[10];
        strcpy(localitate, "Bucuresti");

        tara = new char[8];
        strcpy(tara, "Romania");
    }

    Adresa(const char* const strada_, const int nr_,
           const char* const localitate_="Bucuresti",
           const char* const tara_="Romania",
           const int codpostal_=0, const int sector_=0){

        strada = new char[strlen(strada_) + 1];
        strcpy(strada, strada_);

        nr = nr_;
        codpostal = codpostal_;
        sector = sector_;

        localitate = new char[strlen(localitate_) + 1];
        strcpy(localitate, localitate_);

        tara = new char[strlen(tara_) + 1];
        strcpy(tara, tara_);
    }

    Adresa(const Adresa &a){
        strada = new char[strlen(a.strada) + 1];
        strcpy(strada, a.strada);

        nr = a.nr;
        codpostal = a.nr;
        sector = a.sector;

        localitate = new char[strlen(a.localitate) + 1];
        strcpy(localitate, a.localitate);

        tara = new char[strlen(a.tara) + 1];
        strcpy(tara, a.tara);

    }

    Adresa& operator=(const Adresa &a){
        if(&a == this)
            return *this;
        delete [] strada;
        strada = new char[strlen(a.strada) + 1];
        strcpy(strada, a.strada);

        nr = a.nr;
        codpostal = a.codpostal;
        sector = a.sector;

        delete [] localitate;
        localitate = new char[strlen(a.localitate) + 1];
        strcpy(localitate, a.localitate);

        delete [] tara;
        tara = new char[strlen(a.tara) + 1];
        strcpy(tara, a.tara);
        return *this;
    }
    ~Adresa(){
        delete [] strada;
        delete [] localitate;
        delete [] tara;
    }
    friend std::ostream& operator<<(std::ostream& os, const Adresa& a);
    friend std::istream& operator>>(std::istream& is, Adresa& a);
    friend std::ifstream& operator>>(std::ifstream& is, Adresa& a);
};

class Camin;

class Locatar{
    int CNP;
    char *nume;
    Camin *camin;
    char *facultate;
    int an;
    int camera;
    bool dosarSocial;

    void SetCNP(const int CNP_){  //poate aduce erori
        CNP = CNP_;
    }

public:
    int GetCNP() const{
        return CNP;
    }
    void SetNume(const char *const nume_) {
        delete[] nume;
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);
    }

    char *GetNume() const{
        return nume;
    }

    void SetCamin(Camin &c_);
    void RemoveCamin();

    Camin& GetCamin() const{
        return *camin;
    }
    bool AreCamin(){
        return camin!=nullptr;
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

    void AfisDate() const;

    Locatar(){
        CNP = nranonim++;
        nume = new char[7];
        strcpy(nume, "anonim");

        camin = nullptr;

        facultate = new char[7];
        strcpy(facultate, "anonim");

        an = 0;
        camera = 0;
        dosarSocial = false;
    };

    Locatar(const int CNP_, const char* const nume_, Camin &c_,
            const char* const facultate_, const int an_,
            const int camera_, const bool dosarSocial_= false){

        CNP = CNP_;
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        camin = nullptr;

        facultate = new char[strlen(facultate_) + 1];
        strcpy(facultate, facultate_);

        an = an_;
        camera = camera_;
        dosarSocial = dosarSocial_;
        SetCamin(c_);
    }

    Locatar(const Locatar &l){
        CNP = l.CNP;
        nume = new char[strlen(l.nume) + 1];
        strcpy(nume, l.nume);

        camin = l.camin;

        facultate = new char[strlen(l.facultate) + 1];
        strcpy(facultate, l.facultate);

        an = l.an;
        camera = l.camera;
        dosarSocial = l.dosarSocial;
    }

    ~Locatar(){

        delete [] nume;
        delete [] facultate;
    }

    Locatar& operator=(const Locatar &l){
        if(&l == this)
            return *this;
        CNP = l.CNP;

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
        return *this;
    }

    bool operator==(const Locatar &l) const{
        return (l.CNP == CNP);
    }

    bool operator!=(const Locatar &l) const{
        return !(*this == l);
    }

    friend std::ostream& operator<<(std::ostream& os, const Locatar &l);
    friend std::istream& operator>>(std::istream& is, Locatar &l);
    friend std::ifstream& operator>>(std::ifstream& is, Locatar &l);
};

class Camin {
    char *nume;
    char *admin;
    char *corp;
    int capacitate;
    Locatar **locatari;
    int nrloc;  //nr curent de locatari
    int nrcam;  //nr de camere
    int taxa;
    Adresa adresa;

    void AdaugaLocatar(Locatar &l){    //a nu se apela, decat in Locatar::SetCamin()
        locatari[nrloc] = &l;
        nrloc++;
    }

    void EliminaLocatar(const Locatar &l){  //pana o sa adaug un cod de identificare al fiecarui loc
        int i=0;
        while(*locatari[i]!=l)
            i++;
        for(int j=i; j<nrloc-1; j++)
            locatari[j]=locatari[j+1];
        nrloc--;
    }
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

    void SetCapacitate(const int capacitate_) {
        capacitate = capacitate_;

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


    void AfisLocatari() const{
        if(nrloc == 0) std::cout<<"Caminul este gol.\n";
        for(int i=0; i<nrloc; i++)
            std::cout<<*locatari[i];
    }

    void SetNrcam(const int nrcam_) {
        nrcam = nrcam_;
    }

    int GetNrcam() const {
        return nrcam;
    }

    void SetTaxa(const int taxa_) {
        taxa = taxa_;
    }

    int GetTaxa() const {
        return taxa;
    }

    void SetAdresa(const Adresa &a){
        adresa = a;
    }

    Adresa GetAdresa() const{
        return adresa;
    }

    Camin(){
        nume = new char[7];
        strcpy(nume, "anonim");
        corp = new char[2];
        strcpy(corp, "?");
        nrloc = 0;
        locatari= nullptr;
        capacitate = 0;
        nrcam = 0;
        taxa = 0;
        admin = new char[7];
        strcpy(admin, "anonim");
    }
    Camin(const char* const nume_, const char* const corp_,
          const int capacitate_, const int nrcam_, int taxa_,
          const Adresa &a, const char* const admin_="anonim",
          const int nrloc_=0, Locatar** const locatari_=nullptr){

        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        corp = new char[strlen(corp_) + 1];
        strcpy(corp, corp_);

        capacitate = capacitate_;
        nrcam = nrcam_;
        taxa = taxa_;

        locatari = new Locatar*[capacitate];

        admin = new char[strlen(admin_)+1];
        strcpy(admin, admin_);

        if(nrloc_!=0 && locatari_==nullptr){
            std::cout<<"Nu ati setat care sunt locatarii!\n";
            nrloc = 0;
        }
        else {
            nrloc = nrloc_;
            for (int i = 0; i < nrloc; i++) {
                locatari[i] = locatari_[i];
            }
        }
        adresa = a;
    }
    Camin(const Camin &c){
        nume = new char[strlen(c.nume) + 1];
        strcpy(nume, c.nume);

        corp = new char[strlen(c.corp) + 1];
        strcpy(corp, c.corp);

        capacitate = c.capacitate;
        nrcam = c.GetNrcam();
        taxa = c.taxa;

        locatari = new Locatar*[capacitate];

        admin = new char[strlen(c.admin)+1];
        strcpy(admin, c.admin);

        if(c.nrloc!=0 && c.locatari==nullptr){
            std::cout<<"Nu ati setat care sunt locatarii!\n";
            nrloc = 0;
        }
        else {
            SetNrloc(c.nrloc);
            for (int i = 0; i < nrloc; i++) {
                locatari[i] = c.locatari[i];
            }
        }
        adresa = c.adresa;
    }
    ~Camin(){
        delete [] nume;
        delete [] admin;
        delete [] corp;
        delete [] locatari;
    }

    Camin& operator=(const Camin& c){
        if(&c == this)
            return *this;
        delete [] nume;
        nume = new char[strlen(c.nume) + 1];
        strcpy(nume, c.nume);

        delete [] corp;
        corp = new char[strlen(c.corp) + 1];
        strcpy(corp, c.corp);

        capacitate = c.capacitate;
        nrcam = c.GetNrcam();
        taxa = c.taxa;

        delete [] locatari;
        locatari = new Locatar*[capacitate];

        delete [] admin;
        admin = new char[strlen(c.admin)+1];
        strcpy(admin, c.admin);

        if(c.nrloc!=0 && c.locatari==nullptr){
            std::cout<<"Nu ati setat care sunt locatarii!\n";
            nrloc = 0;
        }
        else {
            nrloc = c.nrloc;
            for (int i = 0; i < nrloc; i++) {
                locatari[i] = c.locatari[i];
            }
        }
        adresa = c.adresa;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &os, const Camin &c);
    friend std::istream& operator>>(std::istream& is, Camin &c);
    friend std::ifstream& operator>>(std::ifstream& is, Camin &c);
    friend void Locatar::SetCamin(Camin &c_);
    friend void Locatar::RemoveCamin();
};

std::ostream& operator<<(std::ostream& os, const Adresa& a){
    os<<a.GetStrada()<<", nr. "<<a.GetNr();
    if(a.GetSector() != 0)os<<", sector "<<a.GetSector();
    if(a.GetCodpostal() != 0)os<<", "<<a.GetCodpostal();
    if(strcmp(a.GetLocalitate(), "Bucuresti") != 0){
        os<<std::endl<<a.GetLocalitate();
        if(strcmp(a.GetTara(), "Romania") != 0)
            os<<", "<<a.GetTara();
    }
    os<<"\n";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Camin &c){
    os<<"Caminul "<<c.GetNume()<<' '<<c.GetCorp()<<std::endl;
    if(strcmp(c.GetAdresa().GetStrada(), "anonim") != 0 and c.GetAdresa().GetNr() != 0)
        os<<"Este situat la adresa:\n"<<c.GetAdresa();
    os<<"Capacitate: "<<c.GetCapacitate()<<std::endl;
    os<<"Taxa: "<<c.GetTaxa()<<"RON"<<std::endl;
    if(strcmp("anonim", c.GetAdmin()) != 0){
        os<<"Administrator: "<<c.GetAdmin()<<"\n";
    }
    os<<"Doriti sa se afiseze datele locatarilor? (Da/Nu)\n";
    char s[3];
    std::cin>>s;
    if(strcmp(s, "Da") == 0) {
        c.AfisLocatari();
        std::cout << "Inserati 'ok' pentru a continua\n";
        std::cin>>s;
        std::cout << "\n";
    }
    std::cout<<"\n";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Locatar &l){
    os<<l.GetNume()<<", "<<l.GetCamera()<<", CNP "<<l.GetCNP()<<"\n";
    return os;
}

std::istream& operator>>(std::istream& is, Adresa &a){
    char s[100];
    std::cout<<"Setati adresa caminului\nStrada: ";
    is>>s;
    a.SetStrada(s);
    int n;
    std::cout<<"Nr: "; std::cin>>n; a.SetNr(n);
    std::cout<<"Caminul se afla in Bucuresti, Romania? ('Da'/'Nu')\n";
    is.get();
    is>>s;
    if(strcmp(s, "Nu") == 0){
        std::cout<<"Setati localitatea: ";
        is>>s; a.SetLocalitate(s);
        std::cout<<"Setati tara: ";
        is>>s; a.SetTara(s);
    }
    std::cout<<"Doriti sa stabiliti detalii despre adresa(codpostal, sector)? ('Da'/'Nu')\n";
    is>>s;
    if(strcmp(s, "Da") == 0){
        std::cout<<"Setati codpostal: ";
        is>>n; a.SetCodpostal(n);
        std::cout<<"Setati sectorul(0 daca nu are sector): ";
        is>>n; a.SetSector(n);
        is.get();
    }
    return is;
}
std::ifstream& operator>>(std::ifstream& is, Adresa &a){
    char s[100];
    std::cout<<"Setati adresa caminului\nStrada: ";
    is>>s;
    a.SetStrada(s);
    int n;
    std::cout<<"Nr: "; std::cin>>n; a.SetNr(n);
    std::cout<<"Caminul se afla in Bucuresti, Romania? ('Da'/'Nu')\n";
    is.get();
    is>>s;
    if(strcmp(s, "Nu") == 0){
        std::cout<<"Setati localitatea: ";
        is>>s; a.SetLocalitate(s);
        std::cout<<"Setati tara: ";
        is>>s; a.SetTara(s);
    }
    std::cout<<"Doriti sa stabiliti detalii despre adresa(codpostal, sector)? ('Da'/'Nu')\n";
    is>>s;
    if(strcmp(s, "Da") == 0){
        std::cout<<"Setati codpostal: ";
        is>>n; a.SetCodpostal(n);
        std::cout<<"Setati sectorul(0 daca nu are sector): ";
        is>>n; a.SetSector(n);
        is.get();
    }
    return is;
}

std::istream& operator>>(std::istream& is, Camin &c){
    char s[100];
    int n;
    std::cout<<"Dati numele caminului:\n";
    is>>s;
    c.SetNume(s);

    std::cout<<"Introduceti corpul caminului:\n";
    is>>s;
    c.SetCorp(s);

    std::cout<<"Introduceti capacitatea de gazduire a caminului(numar posibil de studenti gazduiti):";
    is>>n;
    c.SetCapacitate(n);
    std::cout<<"Introduceti numarul de camere al caminului:";
    is>>n;
    c.SetNrcam(n);
    std::cout<<"Introduceti taxa caminului pe o luna(RON):";
    is>>n;
    c.SetTaxa(n);
    c.locatari = new Locatar*[c.GetCapacitate()];
    std::cout<<"Introduceti numele administratorului caminului:\n";
    is.get();
    is>>s;
    c.SetAdmin(s);
    Adresa a;
    is>>a;
    c.SetAdresa(a);
    return is;
}
std::ifstream& operator>>(std::ifstream& is, Camin &c){
    char s[100];
    int n;
    std::cout<<"Dati numele caminului:\n";
    is>>s;
    c.SetNume(s);

    std::cout<<"Introduceti corpul caminului:\n";
    is>>s;
    c.SetCorp(s);

    std::cout<<"Introduceti capacitatea de gazduire a caminului(numar posibil de studenti gazduiti):";
    is>>n;
    c.SetCapacitate(n);
    std::cout<<"Introduceti numarul de camere al caminului:";
    is>>n;
    c.SetNrcam(n);
    std::cout<<"Introduceti taxa caminului pe o luna(RON):";
    is>>n;
    c.SetTaxa(n);
    c.locatari = new Locatar*[c.GetCapacitate()];
    std::cout<<"Introduceti numele administratorului caminului:\n";
    is.get();
    is>>s;
    c.SetAdmin(s);
    Adresa a;
    is>>a;
    c.SetAdresa(a);
    return is;
}

std::istream& operator>>(std::istream& is, Locatar &l){
    std::cout<<"Introduceti numele locatarului:\n";
    char s[100];
    int n;
    is>>s; l.SetNume(s);
    std::cout<<"Introduceti CNP-ul: "; is>>n; l.SetCNP(n); is.get();
    std::cout<<"Introduceti facultatea la care este inscris:\n";
    is>>s; l.SetFacultate(s);
    std::cout<<"Introduceti anul de studiu: "; is>>n; l.SetAn(n);
    std::cout<<"Introduceti camera: "; is>>n; l.SetCamera(n);
    std::cout<<"Studentul beneficiaza de dosar social? ('Da'/'Nu')\n";
    is.get();
    is>>s;
    if(strcmp("Da", s)==0)
        l.SetDosarSocial(true);
    else
        l.SetDosarSocial(false);
    ///caminul va fi setat de functia apelanta
    return is;
}
std::ifstream& operator>>(std::ifstream& is, Locatar &l){
    std::cout<<"Introduceti numele locatarului:\n";
    char s[100];
    int n;
    is>>s; l.SetNume(s);
    std::cout<<"Introduceti CNP-ul: "; is>>n; l.SetCNP(n); is.get();
    std::cout<<"Introduceti facultatea la care este inscris:\n";
    is>>s; l.SetFacultate(s);
    std::cout<<"Introduceti anul de studiu: "; is>>n; l.SetAn(n);
    std::cout<<"Introduceti camera: "; is>>n; l.SetCamera(n);
    std::cout<<"Studentul beneficiaza de dosar social? ('Da'/'Nu')\n";
    is.get();
    is>>s;
    if(strcmp("Da", s)==0)
        l.SetDosarSocial(true);
    else
        l.SetDosarSocial(false);
    ///caminul va fi setat de functia apelanta
    return is;
}

Locatar totiLoc[1000];
int nrToti = 0;
Camin camine[50];
int nrcamine = 0;

int main() {
    std::cout<<"Inregistrati un camin\n";
    std::cin>>camine[nrcamine++];
    std::cout<<camine[0];
    int opt = -1;
    int cnp, i, j;
    char s1[100], s2[20];
    while(opt != 0){
        std::cout<<"Alegeti o optiune, inserand cifra aferenta\n";
        std::cout<<"0)Inchideti\n";
        std::cout<<"1)Mai inregistrati un camin\n";
        std::cout<<"2)Adaugati(Creati) un locatar la un camin existent\n";
        std::cout<<"3)Scoateti un locatar de la un camin\n";
        std::cout<<"4)Mutati un locatar la un (alt) camin\n";
        std::cout<<"5)Schimbati adresa unui camin\n";
        std::cout<<"6)Afisati datele unui camin\n";
        std::cout<<"7)Afisati datele unui locatar\n";
        std::cout<<"8)Afisati datele tuturor locatarilor\n";
        std::cin>>opt;
        std::cin.get();

        switch(opt) {
            case 1: {
                std::cin >> camine[nrcamine++];
                std::cout << "Inserati 'ok' pentru a continua\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }
            case 2:{
                std::cout << "Introduceti numele caminului in care vreti sa adaugati un locatar\n";
                std::cin>>s1;
                std::cout << "Introduceti corpul caminului\n";
                std::cin>>s2;
                for (i = 0; i < nrcamine; i++)
                    if (strcmp(s1, camine[i].GetNume()) == 0 && strcmp(s2, camine[i].GetCorp()) == 0)
                        break;
                if (i == nrcamine) {
                    std::cout << "Caminul sau corpul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                std::cin >> totiLoc[nrToti];
                bool ok = true;
                for (j = 0; j < nrToti; j++)
                    if (totiLoc[nrToti].GetCNP() == totiLoc[j].GetCNP())
                        ok = false;
                if (!ok) {
                    std::cout << "Locatarul exista deja! ";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                totiLoc[nrToti].SetCamin(camine[i]);
                nrToti++;

                std::cout<<"Studentul a fost adaugat cu succes! ";
                std::cout << "Inserati 'ok' pentru a continua.\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }
            case 3: {
                std::cout << "Dati CNP-ul persoanei pe care vreti sa o scoateti din camin: ";
                std::cin >> cnp;
                for (i = 0; i < nrToti; i++)
                    if (totiLoc[i].GetCNP() == cnp) {
                        totiLoc[i].RemoveCamin();
                        break;
                    }
                if (i == nrToti) {
                    std::cout << "Locatarul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                std::cout << "Locatarul a fost scos din camin. Scrieti 'ok' pentru a continua.\n";
                std::cin.get();
                std::cin>>s2;
                break;
            }
            case 4: {
                std::cout << "Dati CNP-ul persoanei pe care vreti sa o mutati: ";
                std::cin >> cnp;
                for (i = 0; i < nrToti; i++)
                    if (totiLoc[i].GetCNP() == cnp) {
                        break;
                    }
                if (i == nrToti) {
                    std::cout << "Locatarul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                std::cout << "Introduceti numele caminului unde vreti sa mutati noul locatar:\n";
                std::cin.get();
                std::cin>>s1;
                std::cout << "Introduceti corpul caminului\n";
                std::cin>>s2;
                for (j = 0; j < nrcamine; j++)
                    if (strcmp(s1, camine[j].GetNume()) == 0 && strcmp(s2, camine[j].GetCorp()) == 0)
                        break;
                if (j == nrcamine) {
                    std::cout << "Caminul sau corpul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                totiLoc[i].SetCamin(camine[j]);

                std::cout<<"Studentul a fost mutat cu succes! ";
                std::cout << "Inserati 'ok' pentru a continua\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }

            case 5:{
                std::cout << "Introduceti numele caminului a carui adresa doriti sa o schimbati:\n";
                std::cin>>s1;
                std::cout << "Introduceti corpul caminului\n";
                std::cin>>s2;
                for (j = 0; j < nrcamine; j++)
                    if (strcmp(s1, camine[j].GetNume()) == 0 && strcmp(s2, camine[j].GetCorp()) == 0)
                        break;
                if (j == nrcamine) {
                    std::cout << "Caminul sau corpul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                Adresa a;
                std::cin>>a;
                camine[j].SetAdresa(a);
                std::cout<<"Adresa a fost schimbata cu succes! ";
                std::cout << "Inserati 'ok' pentru a continua\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }
            case 6: {
                std::cout << "Introduceti numele caminului pe care vreti sa-l afisati:\n";
                std::cin>>s1;
                std::cout << "Introduceti corpul caminului\n";
                std::cin>>s2;
                for (j = 0; j < nrcamine; j++)
                    if (strcmp(s1, camine[j].GetNume()) == 0 && strcmp(s2, camine[j].GetCorp()) == 0)
                        break;
                if (j == nrcamine) {
                    std::cout << "Caminul sau corpul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                std::cout << camine[j];
                break;
            }
            case 7: {
                std::cout << "Dati CNP-ul studentului ale carui date doriti sa le vedeti: ";
                std::cin >> cnp;
                std::cin.get();
                for (i = 0; i < nrToti; i++)
                    if (totiLoc[i].GetCNP() == cnp) {
                        break;
                    }
                if (i == nrToti) {
                    std::cout << "Locatarul nu exista!\n";
                    std::cout << "Inserati 'ok' pentru a continua\n";
                    std::cin>>s2;
                    std::cout << "\n";
                    break;
                }
                totiLoc[i].AfisDate();
                std::cout << "Inserati 'ok' pentru a continua\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }
            case 8: {
                for (i = 0; i < nrcamine; i++) {
                    std::cout << "Camin " << camine[i].GetNume() << ", " << camine[i].GetCorp() << "\n";
                    camine[i].AfisLocatari();
                    std::cout << "\n";
                }

                for(i=0; i<nrToti; i++)
                    if(! totiLoc[i].AreCamin())
                        std::cout<<totiLoc[i]<<"Fara camin\n";
                std::cout << "Inserati 'ok' pentru a continua\n";
                std::cin>>s2;
                std::cout << "\n";
                break;
            }
            default:
                break;
        }
    }
    fin.close();
    return 0;
}

//le-am pus aici pentru a avea acces la metodele clasei Camin
void Locatar::AfisDate() const {
    if(camin != nullptr){
        std::cout<<GetCamin().GetNume()<<"\n";
    }
    std::cout<<GetNume()<<", "<<GetCamera()<<std::endl;
    if(camin != nullptr){
        std::cout<<"Corp "<<GetCamin().GetCorp()<<std::endl;
    }
    std::cout<<GetFacultate()<<", anul "<<GetAn();
    if(GetDosarSocial())
        std::cout<<", dosar social";
    std::cout<<"\n\n";
}
void Locatar::SetCamin(Camin &c_) {
    if(camin==&c_) {
        std::cout << "Locatarul este deja in camin!\n";
        return;
    }
    if(c_.GetNrloc() == c_.GetCapacitate()) {
        std::cout << "Caminul a ajuns la capacitatea maxima: " <<c_.GetCapacitate()<<"!\n";
        return;
    }
    if(camin!=nullptr)
        GetCamin().EliminaLocatar(*this);
    camin = &c_;
    GetCamin().AdaugaLocatar(*this);
}
void Locatar::RemoveCamin(){
    if(camin == nullptr){
        std::cout<<"Locatarul oricum nu are camin!\n";
        return;
    }
    GetCamin().EliminaLocatar(*this);
    camin = nullptr;
}
