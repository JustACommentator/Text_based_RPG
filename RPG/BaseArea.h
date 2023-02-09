#pragma once

#include "Entity.h"
#include "Item.h"
#include "PointOfInterest.h"

class BaseArea
{
protected:
	
	std::list<Entity*> entities;
	std::list<BaseArea*> adjacentAreas;
	std::string name;
	std::string description;
	std::list<Item*> items;
	std::list<PointOfInterest*> pointsOfInterest;
	bool canBeEntered;

public:

	BaseArea(std::string _name, std::string _description, bool _canBeEntered, std::list<PointOfInterest*> _pointsOfInterest,
		std::list<Entity*> _entities, std::list<Item*> _items, std::list<BaseArea>) :
		name(_name), description(description), canBeEntered(_canBeEntered), pointsOfInterest(_pointsOfInterest),
		entities(_entities), items(_items) {};

	std::list<Entity*> getEntities() { return entities; }
	void setEntities(std::list<Entity*> _entities) { entities = _entities; }
	void addEntity(Entity* _entity) { entities.push_back(_entity); }

	std::list<BaseArea*> getAdjacentAreas() { return adjacentAreas; }
	void setAdjacentAreas(std::list<BaseArea*> _adjacentAreas) { adjacentAreas = _adjacentAreas; }
	void addAdjacentArea(BaseArea* _adjacentArea) { adjacentAreas.push_back(_adjacentArea); }

	std::list<Item*> getItems() { return items; }
	void setItems(std::list<Item*> _items) { items = _items; }
	void addItem(Item* _item) { items.push_back(_item); }

	std::list<PointOfInterest*> getPointsOfInterest() { return pointsOfInterest; }
	void setPointsOfInterest(std::list<PointOfInterest*> _pointsOfInterest) { pointsOfInterest = _pointsOfInterest; }
	void addPointOfInterest(PointOfInterest* _pointOfInterest) { pointsOfInterest.push_back(_pointOfInterest); }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	std::string getDescription() { return description; }
	void setDescription(std::string _description) { description = _description; }
};