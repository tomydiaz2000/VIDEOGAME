#include <SFML/Graphics.hpp>
using namespace sf;

int main(int argc, char *argv[]){
	////// INICIALIZACION
	RenderWindow window({1000,600},"Video-Game");	/// crea una ventana de 800x600
	window.setFramerateLimit(60);					/// limitamos el FPS
	
	int nave_x, nave_y, meteorito_x, meteorito_y, nave_lado_R, nave_lado_L;
	int nave_lado_B, nave_lado_T, meteorito_lado_R, meteorito_lado_L;
	int meteorito_lado_B, meteorito_lado_T;
	
	Texture fondo_texture;
	Texture nave_t;									/// la textura que vamos a utilizar para el Sprite
	Texture meteorito_t;
	Texture ball_t;											
	nave_t.loadFromFile("img/spaceship.png");		/// se carga desde un archivo
	fondo_texture.loadFromFile("img/space.jpg");
	meteorito_t.loadFromFile("img/meteorito_tamaño1.png");
	ball_t.loadFromFile("img/ball.png");
	
	Sprite fondo;									/// sprites de nuestro juego
	Sprite nave;
	Sprite meteorito;
	Sprite ball;
	fondo.setTexture(fondo_texture);				///Asignamos El fondo a un Sprite
	fondo.setPosition(0,0);							///Asignamos una posicion
	meteorito.setTexture(meteorito_t);
	meteorito.setPosition(rand()%(750), 0);
	meteorito.setRotation(-40);						///podemos rotar el Sprite
	nave.setTexture(nave_t);	
	nave.setPosition(440, 520);	
	ball.setTexture(ball_t);
	ball.setPosition(200, 200);
	ball.setScale(2, 2);  									
	
	Vector2f naveVel;	/// vector para almacenar la velocidad del sprite
	Vector2f meteoritoVel;
	
	////// EL BUCLE DE JUEGO
	while(window.isOpen()) {
		////// EVENTOS
		// polling de la cola de eventos, no lo vamos a usar
		// por ahora pero lo necesitamos para que el juego no se tilde
		Event e;
		while(window.pollEvent(e)) {
			// cerrar la ventana si el usuario hace click en la cruz
			if(e.type == Event::Closed)	{
				window.close();
			}
		}
		
		// si apretamos la flecha hacia la derecha, el sprite adquiere velocidad hacia la derecha
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			naveVel.x = 5;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)){
			naveVel.x = -5;
		}
		else{
			naveVel.x = 0;
		}
		if (meteorito.getPosition().y < 600){
				meteoritoVel.y = 5;
		}
		else{
			meteorito.setPosition(rand()%(750), 0);
		}
		
		//Obtengo las cordenadas de los objetos meteorito y Nave.
		nave_x = nave.getPosition().x;
		nave_y = nave.getPosition().y;
		nave_lado_B = nave_y + 82;
		nave_lado_T = nave_y;
		nave_lado_R = nave_x + 60;
		nave_lado_L = nave_x;
		meteorito_x = meteorito.getPosition().x;
		meteorito_y = meteorito.getPosition().y;
		//meteorito_lado_B = meteorito_y + ;
		meteorito_lado_T = meteorito_y ;
		meteorito_lado_R = meteorito_x;
		//meteorito_lado_L = ;
		//Verifico si la nave y el meteorito se estan chocando
		
		////// ACTUALIZACION
		// movemos al sprite segun la velocidad ajustada en el paso anterior
		nave.move(naveVel);
		meteorito.move(meteoritoVel);
		
		Vector2f posMouse = static_cast<Vector2f>(Mouse::getPosition());
		ball.setPosition(posMouse);
		////// DIBUJADO
		window.clear(Color(255, 255, 255)); /// limpiamos la ventana con el color blanco
		window.draw(fondo);
		window.draw(meteorito);
		window.draw(nave);	/// dibujamos el sprite en la ventana (con la textura, posicion, etc asignados antes)
		window.draw(ball);
		window.display();	/// avisamos que ya terminamos de dibujar para que se actualice la ventana
	}
	return 0;
}

