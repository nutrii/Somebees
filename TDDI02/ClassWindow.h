//=================================
#ifndef ClassWindow.h   // if ClassWindow.h hasn't been included yet...
#define ClassWindow.h   //   #define this so the compiler knows it has been included

//=================================
using namespace std;
//=================================
//Class itself
class Window 
{
	public:
	//Public constructors and destructor
	Window();//Default constructor 
	Window( const Window& );//Copy constructor 
	Window& operator=( const Window& );//Copy assignment operator
	~Window();//Destructor
	
	//Public functions
	void close();//Calls destructor
	bool loadmedia(string);//loads a picture to the screen
	void fillwhite();
	private:
	
	//Private functions
	bool init();//Initializes SDL, Creates window, gets window surface
	void update(); //Updates the screen
	//Variables for size
	int screen_width;
	int screen_height;
	
	//The window we'll be rendering to
	SDL_Window* Render_Window;
	
	//The surface contained by the window
	SDL_Surface* Screen_Surface;
};

//=================================
//Class constructors and destructor.

Window::Window()//Default constructor 
{
	screen_width = 640;
	screen_height = 480;
	bool init();
}

Window::Window( const Window& other )//Copy constructor 
{
	  printf( "Error, not implemented yet\n");
}

Window& Window::operator=( const Window& other )//Copy assignment operator
{
	printf( "Error, not implemented yet\n");
}

Window::~Window()//Destructor
{
    //Destroy window
    SDL_DestroyWindow( Render_Window ); // This also deallocates surfaces that are contained within the window
    Render_Window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

//=================================
//class functions
bool Window::init()
{	
	//Flag
	bool success{true};
	 //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
	  else
    {
        //Create window
        Render_Window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN );
        if( Render_Window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            Screen_Surface = SDL_GetWindowSurface( Render_Window );
        }
    }
	return success;
}

bool Window::loadmedia(string str) 
{
	//The image we will load and show on the screen
	SDL_Surface* image;
	bool success{true};
	const char *cstr = str.c_str();//convert string to char*
	 //Load Image
    image = SDL_LoadBMP( cstr );
    if( image == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", cstr, SDL_GetError() );
        success = false;
    }
	else
	{
		SDL_BlitSurface( image, NULL, Screen_Surface, NULL );
		 //Update the surface
		update();
	}
    
	//Deallocate surface
	SDL_FreeSurface( image );
    image= NULL;

    return success;
}

void Window::update()
{
	SDL_UpdateWindowSurface( Render_Window );
}

void Window::fillwhite()
{
  //Fill the surface white
    SDL_FillRect( Screen_Surface, NULL, SDL_MapRGB( Screen_Surface->format, 0xFF, 0xFF, 0xFF ) );
            
   //Update the surface
    update();

   //Wait two seconds
    SDL_Delay( 2000 );
}

void Window::close()//calls destructor
{
	delete this;
}
#endif 