 #include <iostream>
 #include <string>
 #include <stack>
 //Juan Miguel Regalado Nuño
 using namespace std;

 // Funci�3n que devuelve la precedencia de un operador
 int obtenerPrecedencia(char operador) {
 switch (operador) {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 case '^':
 return 3;
 default:
 return 0;
 }
 }
 // Funci�3n que convierte una expresi�3n infija a posfija utilizando una pila
//estática
 string infijaAPosfija(string expresion) {
 string posfija = "";
 stack<char> pila;
 for (int i = 0; i < expresion.length(); i++) {
 char caracter = expresion[i];
 // Si el caracter es un d�gito o una letra, se agrega directamente a
//la expresi�3n posfija
 if (isdigit(caracter) || isalpha(caracter)) {
 posfija += caracter;
 }
 // Si el caracter es un paréntesis izquierdo, se agrega a la pila
 else if (caracter == '(') {
 pila.push(caracter);
 }
 // Si el caracter es un paréntesis derecho, se desapilan los
//operadores hasta encontrar el paréntesis izquierdo correspondiente
 else if (caracter == ')') {
 while (!pila.empty() && pila.top() != '(') {
 posfija += pila.top();
 pila.pop();
 }
 // Se elimina el paréntesis izquierdo de la pila
 if (!pila.empty()) {
 pila.pop();
 }
 }
 // Si el caracter es un operador, se desapilan los operadores de
//mayor o igual precedencia y se agrega a la pila
 else if (caracter == '+' || caracter == '-' || caracter == '*' ||
caracter == '/' || caracter == '^') {
 while (!pila.empty() && obtenerPrecedencia(caracter) <=
obtenerPrecedencia(pila.top())) {
 posfija += pila.top();
 pila.pop();
 }
 pila.push(caracter);
 }
 }

 // Se desapilan los operadores restantes
 while (!pila.empty()) {
 posfija += pila.top();
 pila.pop();
 }
 return posfija;
 }

 // Funci�3n principal
 int main() {

 string expresion;
 cout << "Ingrese una expresion infija: ";
 getline(cin, expresion);
 string posfija = infijaAPosfija(expresion);
 cout << "La expresion posfija es: " << posfija << endl;
 return 0;
 }
