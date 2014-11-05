DishBasedReasoning
==================

A Case Based Reasoner which recommends food dishes

==================
Mechanism

	Case:
		A series of likes and dislikes which has an associated with a particular dish that satisfies that need.
	Dish:
		A series of attributes that is associated with ingredients, tastes, or textures.

Each query to the recommendation system is a case in an of itself. So the system defines how to define the similarity between two cases. This similarity is used to define which case(that has a solution) should be used as a recommendation.