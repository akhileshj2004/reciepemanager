1.List of objects identified: 
	Ingredient: Represents an ingredient used in recipes.
	RecipeBase: Abstract base class for recipes, containing common attributes and methods.
	VegetarianRecipe: Derived from `RecipeBase`, represents a specific type of recipe (vegetarian).
	NonVegetarianRecipe: Derived from `RecipeBase`, represents another specific type of recipe (non-vegetarian).
	User: Represents a user who interacts with recipes, storing preferred ingredients and favorite/submitted recipes.
	RecipeManager: Manages a collection of recipes, providing operations like addition, removal, and searching.

 2. Identified and applied standard design patterns:
	Factory Method Pattern: Used indirectly when adding recipes (`addRecipe` function) where the choice determines whether to create a `VegetarianRecipe` or `NonVegetarianRecipe`.
	Iterator Pattern: Implicitly used when iterating over recipes in `RecipeManager`.
	Observer Pattern: Partially implemented with `displayRatings` method in `RecipeBase` and the `User` class's storage of favorite recipes.
	Singleton Pattern: Not explicitly used in the provided code.

3. Description of each class:
	Ingredient:
•	Attributes: `name` (string).
•	Relationships: None.
•	OOP Concepts: Simple encapsulation.

	RecipeBase(Abstract class):
•	Attributes: `name`, `description`, `category`, `ingredients` (vector of `Ingredient`), `ratings` (vector of int).
•	Methods: `display()`, `getAverageRating()`, `addRating()`, `containsIngredient()`, `displayRatings()`.
•	Relationships: Uses `Ingredient` objects. Has-a relationship with `ratings`.
•	OOP Concepts: Encapsulation (attributes and methods), Inheritance (abstract class), Polymorphism (virtual methods).

	VegetarianRecipe and NonVegetarianRecipe:
•	Inheritance: Both inherit from `RecipeBase`.
•	Methods: `display()` (overridden), displaying specific recipe type details.
•	Relationships: Inherit all attributes and methods from `RecipeBase`.
•	OOP Concepts: Specialization via inheritance and polymorphism.


	User:
•	Attributes: `name`, `preferredIngredients` (vector of `Ingredient`), `favoriteRecipes` (vector of `RecipeBase*`), `submittedRecipes` (vector of `RecipeBase*`).
•	Methods: `addPreferredIngredient()`, `addFavoriteRecipe()`, `addSubmittedRecipe()`, `displaySubmittedRecipes()`.
•	Relationships: Has-a relationship with `Ingredient` and `RecipeBase`.
•	OOP Concepts: Encapsulation (data members and methods), Aggregation (with `Ingredient` and `RecipeBase*`).

	RecipeManager:
•	Attributes: `recipes` (vector of `RecipeBase*`).
•	Methods: `addRecipe()`, `removeRecipe()`, `searchByIngredient()`, `searchByName()`, `searchByRating()`, `displayAllRecipes()`, `getTopRatedRecipes()`.
•	Relationships: Owns `RecipeBase` objects.
•	OOP Concepts: Encapsulation, Aggregation, Polymorphism (through `RecipeBase` pointers).

4. Main function (Flow of object creation and function call):
•	The `main` function provides a menu-driven interface to interact with `RecipeManager` and other classes.
•	It handles adding, searching, displaying, and removing recipes based on user input.
•	It uses exception handling (`try-catch`) to manage errors and display appropriate messages.
•	Objects are created dynamically (`new`), managed by `RecipeManager`, and eventually deleted in its destructor (`delete`).
