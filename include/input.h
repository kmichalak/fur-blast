#ifndef FUR_BLAST_INPUT_H
#define FUR_BLAST_INPUT_H

// The total number of keys that will be supported by the application.
#define NUMBER_OF_KEYS 4
#define KEY_UP_IDX 0
#define KEY_DOWN_IDX 1
#define KEY_LEFT_IDX 2
#define KEY_RIGHT_IDX 3


class InputManager {
 public:
  static InputManager &getInstance();
  void update();
 private:
  // Hide possibility of object instantiation
  InputManager() :
      keyboard(nullptr) { };

  // Delete methods (new C++11 - http://www.stroustrup.com/C++11FAQ.html#default)
  // and disallow copying object.
  InputManager &operator=(const InputManager &) = default;
  InputManager(const InputManager &) = default;

  const uint8_t *keyboard;
  bool keyUp[NUMBER_OF_KEYS];
  bool keyDown[NUMBER_OF_KEYS];

};

#endif //FUR_BLAST_INPUT_H
