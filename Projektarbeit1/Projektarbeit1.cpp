// Projektarbeit

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu\AutoLink.hpp>


int32_t a;
double x;
double y;



class GameWindow : public Gosu::Window {
public:
	Gosu::Image bild;
	GameWindow()
		: Window(640, 480)
		,bild("KUH.png")
	{
		set_caption("Gosu Tutorial Game");
	}
	
	void update() override {
		a = (a + 1)%640;

		x = input().mouse_x();
		y = input().mouse_y();
	}

	void draw() override {
			// Linie 
			graphics().draw_line(
			20, 20, Gosu::Color::BLUE,
			200, 20, Gosu::Color::BLUE,
			0.0
			);

			//dreieck MAuszeiger
			Gosu::Graphics::draw_triangle(
				x, y, Gosu::Color::RED,
				200, 100, Gosu::Color::GREEN,
				200, 400, Gosu::Color::BLUE,
				0.0
			);
			
			//Dreieck bewegich
			graphics().draw_triangle(
			a, 20, Gosu::Color::RED,
			100, 80, Gosu::Color::RED,
			a, 120, Gosu::Color::RED,
			0.0
		);

			//BILD
			bild.draw_rot(x, y, 0.0,
				0.0, // Rotationswinkel in Grad
				0.5, 0.5 // Position der "Mitte" relativ zu x, y
			);
		
	}



};




int main(){


	GameWindow window;
	window.show();

	
}