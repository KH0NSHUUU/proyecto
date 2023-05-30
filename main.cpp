#include<iostream>
#include<fstream>
using namespace std;
struct Auto
{
    string patente, marca, modelo, color, anio, disponible;
}autos[10];
struct Personas
{
    string nombre, apellido, direccion, telefono, correo, dni;
}clientes[10];
struct Alquiler
{
    Auto autoa;
    Personas personasa;
    string fecha;
}al[10];
int op, np=0, na=0, nalq=0;
//Menus
void mostrarMenu();
void menuAlquiler();
void menuClientes();
void menuAutos();
//Clientes
void altaClientes(Personas cli[], int& np);
void bajaClientes(Personas cli[], int& np);
void listarClientes(Personas cli[], int& np);
void cargarClientesArchivo(Personas cli[], int& np);
void guardarClientesArchivo(Personas cli[], int& np);
void modificarClientes(Personas cli[], int&np);
//Autos
void altaAutos(Auto au[], int& na);
void bajaAutos(Auto au[], int& na);
void listarAutos(Auto aut[], int& na);
void cargarAutosArchivo(Auto aut[], int& na);
void guardarAutosArchivo(Auto aut[], int& na);
void modificarAutos(Auto aut[], int& na);
//Alquiler
void altaAlquiler(Alquiler al[], int& nalq, Personas cli[], int& np, Auto aut[], int& na);
int main(){
    cout<<"\t\tBienvenidos al programa de alquiler de autos"<<endl;
    system("pause");
    system("cls");
    mostrarMenu();
    return 0;
}
void mostrarMenu(){
    cargarAutosArchivo(autos, na);
    cargarClientesArchivo(clientes, np);
    do
    {
        cout<<"----------MENU----------"<<endl;
        cout<<"[1]---> Alquiler"<<endl;
        cout<<"[2]---> Clientes"<<endl;
        cout<<"[3]---> Autos"<<endl;
        cout<<"[4]---> Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch(op)
        {
            case 1:
                menuAlquiler();
                break;
            case 2:
                menuClientes();
                break;
            case 3:
                menuAutos();
                break;
            case 4:
                break;
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=4);
}
void menuAlquiler(){
    do
    {
        cout<<"----------MENU Alquiler----------"<<endl;
        cout<<"[1]---> Alta Alquiler"<<endl;
        cout<<"[2]---> Baja Alquiler"<<endl;
        cout<<"[3]---> Listar Alquileres"<<endl;
        cout<<"[4]---> Volver al Menu Principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=4);
}
void menuClientes(){
    do
    {
        cout<<"----------MENU Clientes----------"<<endl;
        cout<<"[1]---> Alta Clientes"<<endl;
        cout<<"[2]---> Baja Clientes"<<endl;
        cout<<"[3]---> Modificar Clientes"<<endl;
        cout<<"[4]---> Listar Clientes"<<endl;
        cout<<"[5]---> Volver al Menu Principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                altaClientes(clientes,na);
                guardarClientesArchivo(clientes,na);
                break;
            case 2:
                bajaClientes(clientes,na);
                guardarClientesArchivo(clientes,na);
            case 3:
                break;
            case 4:
                listarClientes(clientes, na);
            case 5:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                break;
        }
    } while (op!=5);
}
void menuAutos(){
    do
    {
        cout<<"----------MENU Autos----------"<<endl;
        cout<<"[1]---> Alta Autos"<<endl;
        cout<<"[2]---> Baja Autos"<<endl;
        cout<<"[3]---> Modificar Autos"<<endl;
        cout<<"[4]---> Listar Autos"<<endl;
        cout<<"[5]---> Volver al Menu Principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                altaAutos(autos,na);
                guardarAutosArchivo(autos,na);
                break;
            case 2:
                bajaAutos(autos,na);
                guardarAutosArchivo(autos,na);
            case 3:
                break;
            case 4:
                listarAutos(autos, na);
            case 5:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=5);
}
//Funciones Clientes
void altaClientes(Personas cli[], int& np){
    Personas ncli;
    
    cout<<"Ingrese los datos del cliente"<<endl;
    fflush(stdin);
    cout<<"Apellido: "<<endl;
    cin.ignore();
    getline(cin,ncli.apellido);
    fflush(stdin);
    cout<<"Nombre: "<<endl;
    fflush(stdin);
    getline(cin,ncli.nombre);
    fflush(stdin);    
    cout<<"Dni: "<<endl;
    fflush(stdin);
    cin>>ncli.dni;
    cin.ignore();
    cout<<"Direccion: "<<endl;
    fflush(stdin);
    getline(cin,ncli.direccion);
    fflush(stdin);
    cout<<"Telefono: "<<endl;
    fflush(stdin);
    getline(cin,ncli.telefono);
    fflush(stdin);
    cout<<"Correo: "<<endl;
    fflush(stdin);
    getline(cin,ncli.correo);
    fflush(stdin);
    system("clear");
    cout<<"Persona cargada correctamente. "<<endl;
    cli[np]=ncli;
    np++;
}
void bajaClientes(Personas cli[], int& np){
    string dni;
    cout<<"Ingrese el DNI de la persona a dar de baja"<<endl;
    cin>>dni;
    bool b=false;
    for (int i = 0; i < np; i++)
    {
        if(cli[i].dni==dni){
            b=true;
            for (int j = i; j < np-1; j++)
            {
                cli[i]=cli[j+1];
            }
            np--;
            cout<<"Personas eliminada correctamente"<<endl;
            break;
        }
    }
}
void listarClientes(Personas cli[], int& np){
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|   Dni   |   Nombre   |   Apellido   |   Direccion   |   Telefono   |   Correo   |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++) {
        printf("|%-11s|%-11s|%-12s|%-11s|%-9s|%-17s|\n",cli[i].dni.c_str(), cli[i].nombre.c_str(), cli[i].apellido.c_str(), cli[i].direccion.c_str(), cli[i].telefono.c_str(), cli[i].correo.c_str());
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    
}
void modificarClientes(){
    cout<<"alquilar autos"<<endl;
    system("pause");
    system("cls");
}
void guardarClientesArchivo(Personas cli[], int&np){
    ofstream archivo("cliente.txt");
    for(int i=0;i<np;i++){
        archivo<<cli[i].dni<<","<<cli[i].nombre<<","<<cli[i].apellido<<","<<cli[i].direccion<<","<<cli[i].telefono<<","<<cli[i].correo<<","<<endl;
    }
    archivo.close();
}
void cargarClientesArchivo(Personas cli[], int&np){
    ifstream archivo("cliente.txt");
    string linea;
    int tam=0;
    while (getline(archivo,linea))
    {
        tam++;
    }
    archivo.close();
    archivo.open("cliente.txt");
    while(getline(archivo,linea)){
        Personas a;
        int pos=0, campo=0;
        string temp;
        while (pos<linea.length())
        {
            if(linea[pos]==','){
                switch (campo)
                {
                    case 0:
                        a.dni=temp;
                        break;
                    case 1:
                        a.nombre=temp;
                        break;
                    case 2:
                        a.apellido=temp;
                        break;
                    case 3:
                        a.direccion=temp;
                        break;
                    case 4:
                        a.telefono=temp;
                        break;
                    case 5:
                        a.correo=temp;
                        break;
                    default:
                        break;
                }
                campo++;
                temp="";
            }
            else{
                temp += linea[pos];
            }
            pos++;
        }
        cli[np]=a;
        np++;
    }
    archivo.close();
}
//Funciones Autos
void listarAutos(Auto aut[], int& na) {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|   Patente   |   Marca   |   Modelo   |   Color   |   Año   |   Disponible   |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < na; i++) {
        printf("|%-13s|%-11s|%-12s|%-11s|%-9s|%-17s|\n",aut[i].patente.c_str(), aut[i].marca.c_str(), aut[i].modelo.c_str(), aut[i].color.c_str(), aut[i].anio.c_str(), aut[i].disponible.c_str());
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}
void altaAutos(Auto aut[], int& na){
    Auto au;
    int aux;
    cout<<"Ingrese los datos de auto"<<endl;
    cin.ignore();
    cout<<"Patente: "<<endl;
    fflush(stdin);
    getline(cin,au.patente);
    cout<<"Marca: "<<endl;
    fflush(stdin);
    getline(cin,au.marca);
    cout<<"Modelo: "<<endl;
    fflush(stdin);
    getline(cin,au.modelo);
    cout<<"Color: "<<endl;
    fflush(stdin);
    getline(cin,au.color);
    cout<<"Anio: "<<endl;
    cin>>au.anio;
    cout<<"Disponibilidad [0: disponible]-[1: no disponible]: "<<endl;
    cin>>aux;
    if (aux==0){
        au.disponible=true;
    }
    else{
        au.disponible=false;
    }
    aut[na]=au;
    na++;
    
}
void bajaAutos(Auto aut[], int& na){
    string pate;
    cout<<"Ingrese la patente del auto a dar de baja: "<<endl;
    cin.ignore();
    getline(cin,pate);
    bool b=false;
    for (int i = 0; i < na; i++)
    {
        if(aut[i].patente==pate){
            b=true;
            for (int j = i; j < na-1; j++)
            {
                aut[j]=aut[j+1];
            }
            na--;
            cout<<"Auto eliminado correctamente."<<endl;
            break;
        }
    }
    
}
void modificarAutos(){
    cout<<"listar autos"<<endl;
    system("pause");
    system("cls");
}
void cargarAutosArchivo(Auto aut[], int& na){
    ifstream archivo("autos.txt");
    string linea;
    int tam=0;
    while (getline(archivo,linea))
    {
        tam++;
    }
    archivo.close();
    archivo.open("autos.txt");
    while(getline(archivo,linea)){
        Auto a;
        int pos=0, campo=0;
        string temp;
        while (pos<linea.length())
        {
            if(linea[pos]==','){
                switch (campo)
                {
                    case 0:
                        a.patente=temp;
                        break;
                    case 1:
                        a.marca=temp;
                        break;
                    case 2:
                        a.modelo=temp;
                        break;
                    case 3:
                        a.color=temp;
                        break;
                    case 4:
                        a.anio=temp;
                        break;
                    case 5:
                        a.disponible=temp;
                        break;
                    default:
                        break;
                }
                campo++;
                temp="";
            }
            else{
                temp += linea[pos];
            }
            pos++;
        }
        aut[na]=a;
        na++;
    }
    archivo.close();
    
}
void guardarAutosArchivo(Auto aut[], int& na){
    ofstream archivo("autos.txt");
    for(int i=0;i<na;i++){
        archivo<<aut[i].patente<<","<<aut[i].marca<<","<<aut[i].modelo<<","<<aut[i].color<<","<<aut[i].anio<<","<<aut[i].disponible<<","<<endl;
    }
    archivo.close();
}
//Funciones Alquiler...
void altaAlquiler(Alquiler al[], int& nalq, Personas cli[], int& np, Auto aut[], int& na){
    Alquiler nal;
    
    string dni;
    cout<<"Ingrese el dni de la persona que alquilara"<<endl;
    fflush(stdin);
    getline(cin,dni);
    for (int i = 0; i < np; i++)
    {
        if(cli[i].dni==dni){

        }
    }
    
}