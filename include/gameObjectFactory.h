
#include "StarGameObject.h"
#include <memory>
#include <vector>

class GameObjectFactory {
  public:
	GameObjectFactory() = default;
	void create_object();
	std::vector<Enemy *> get_objs();

  private:
	void add_object(std::unique_ptr<Enemy> obj);
	std::vector<std::unique_ptr<Enemy>> objs;
};
