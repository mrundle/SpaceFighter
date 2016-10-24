all: SpaceFighter

LDFLAGS=-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

OBJS=\
	CApp.o           \
	CApp_OnInit.o    \
	CApp_OnEvent.o   \
	CApp_OnLoop.o    \
	CApp_OnRender.o  \
	CApp_OnCleanup.o \
	CSurface.o       \
	CEvent.o         \
	CAnimation.o     \
	CEntity.o        \
	Ship.o           \
	Bullet.o         \
	EnemyShip.o      \
	EnemyBullet.o

SpaceFighter: $(OBJS)
	g++ $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ -c $< -o $@

CApp.o: CApp.cpp
	g++ -c CApp.cpp

clean:
	rm -f *.o SpaceFighter
