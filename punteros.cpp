#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

class ListaSimple{
    private:
        Nodo *inicio;

    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }

        void mostrarListaAdelante() {
            Nodo *temp = inicio;
            if(!inicio){
                cout << "La lista no posee elementos" << endl;
            }else {
                while(temp) {
                    cout << temp->dato << ", ";
                    temp = temp->sig;
                }
                cout<<endl;
            }
        }

        void agregarElemento(int valor) {
            Nodo *n = crearNodo(valor), *temp;
            if(!inicio) {
                inicio = n;
            }else{
                for(temp=inicio;temp->sig;temp = temp->sig);
                temp->sig = n;
            }
        }

        ListaSimple arribaPromedio(){
            Nodo *temp = inicio;
            ListaSimple res;
            if(!inicio){
                cout << "La lista no posee elementos" << endl;
            }else{
                double prom = 0;
                int aux = 0;
                while (temp){
                    prom = prom+temp->dato;
                    temp = temp->sig;
                    aux++;
                }
                prom = prom/aux;
                temp = inicio;
                while(temp){
                    if(temp->dato>prom){

                        res.agregarElemento(temp->dato);
                    }
                    temp = temp->sig;
                }
                cout<<"Promedio: "<<prom<<endl;
                return res;
            }
            return res;
        }

        ListaSimple(){
            inicio = nullptr;
        }
};

int main(){

    ListaSimple L1;
  
    L1.agregarElemento(1);
    L1.agregarElemento(2);
    L1.agregarElemento(6);
    L1.agregarElemento(8);
    L1.agregarElemento(10);
    L1.mostrarListaAdelante();

    ListaSimple promedio = L1.arribaPromedio();

    promedio.mostrarListaAdelante();
    return 0;
}