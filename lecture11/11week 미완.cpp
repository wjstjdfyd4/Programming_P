#include <iostream>
#include <vector>

class Object;

class Component {
public:
    virtual void Update() {}
};

class Scene {
private:
    std::vector<Object*> objects;
    char* screenBuffer;
    int screenWidth;
    int screenHeight;

public:
    Scene(int width, int height) : screenWidth(width), screenHeight(height) {
        screenBuffer = new char[screenWidth * screenHeight];
        InitScreenBuf();
    }

    ~Scene() {
        delete[] screenBuffer;
    }

    void AddObject(Object* object) {
        objects.push_back(object);
    }

    void Draw() {
        ClearScreenBuf();

        for (Object* object : objects) {
            object->Render(screenBuffer);
        }

        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                std::cout << screenBuffer[i * screenWidth + j];
            }
            std::cout << std::endl;
        }
    }

    void InitScreenBuf() {
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                screenBuffer[i * screenWidth + j] = ' ';
            }
        }
    }

    void ClearScreenBuf() {
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                screenBuffer[i * screenWidth + j] = ' ';
            }
        }
    }
};

class Object {
protected:
    int positionX;
    int positionY;
    std::vector<Component*> components;

public:
    Object(int x, int y) : positionX(x), positionY(y) {}

    void AddComponent(Component* component) {
        components.push_back(component);
    }

    virtual void Render(char* screenBuffer) = 0;
};

class SnakeBody : public Object {
public:
    SnakeBody(int x, int y) : Object(x, y) {}

    void Render(char* screenBuffer) override {
        screenBuffer[positionY * screenWidth + positionX] = '*';
    }
};

class GameManager {
private:
    Scene* scene;

public:
    GameManager(int screenWidth, int screenHeight) {
        scene = new Scene(screenWidth, screenHeight);
    }

    ~GameManager() {
        delete scene;
    }

    void RunGame() {
        SnakeBody snakeBody(5, 5);
        scene->AddObject(&snakeBody);

        while (true) {
            scene->Draw();

            // Update game logic
            for (Object* object : scene->GetObjects()) {
                for (Component* component : object->GetComponents()) {
                    component->Update();
                }
            }

            // Handle user input

            // Wait for next frame
        }
    }
};

int main() {
    GameManager gameManager(20, 10);
    gameManager.RunGame();

    return 0;
}
