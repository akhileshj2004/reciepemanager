# 🍽️ Recipe Management System

<p align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B-blue.svg" alt="Language: C++">
  <img src="https://img.shields.io/badge/paradigm-OOP-orange.svg" alt="Paradigm: OOP">
  <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License: MIT">
  <img src="https://img.shields.io/badge/status-stable-brightgreen.svg" alt="Status: Stable">
</p>

A comprehensive C++ application for managing culinary recipes using object-oriented programming principles. This system enables users to create, manage, search, and rate both vegetarian and non-vegetarian recipes.

## ✨ Features

- **Recipe Management**
  - Add vegetarian and non-vegetarian recipes
  - Remove existing recipes
  - View all available recipes

- **Advanced Search Capabilities**
  - Search by ingredient
  - Search by minimum rating
  - Find top-rated recipes

- **Rating System**
  - Add ratings to recipes (scale 1-5)
  - Calculate average ratings
  - Sort and display top-rated recipes

- **User Management**
  - Track user preferred ingredients
  - Manage favorite recipes
  - Monitor submitted recipes

## 🧩 Class Structure

```
┌────────────┐            ┌──────────────┐
│ Ingredient │            │ RecipeManager │
└────────────┘            └──────┬───────┘
                                 │ manages
                                 ▼
┌──────────┐  uses    ┌──────────────┐
│   User   │◄────────►│  RecipeBase  │◄─┐
└──────────┘          └──────┬───────┘  │
                             │          │
                  ┌──────────┴──────────┐
                  │                     │
         ┌────────▼─────┐      ┌────────▼─────────────┐
         │VegetarianRecipe│     │NonVegetarianRecipe  │
         └────────────────┘     └──────────────────────┘
```

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++11 support or higher (GCC, Clang, MSVC)
- Standard C++ libraries

### Compilation

```bash
# Compile the program
g++ -std=c++11 recipe_management.cpp -o recipe_system

# Run the application
./recipe_system
```

## 📋 Usage Guide

### Main Menu

The system offers the following options:

1. **Add Recipe** - Create new vegetarian or non-vegetarian recipes
2. **Search by Ingredient** - Find recipes containing specific ingredients
3. **Search by Rating** - Find recipes meeting a minimum rating threshold
4. **View All Recipes** - Display all recipes in the system
5. **Remove Recipe** - Delete a recipe from the system
6. **Display Top Rated Recipes** - View the highest-rated recipes
7. **Exit** - Close the application

### Adding a Recipe

```
1. Select "Add Recipe" from the main menu
2. Choose recipe type (Vegetarian/Non-Vegetarian)
3. Enter recipe details:
   - Name
   - Description
   - Category
   - Ingredients (type 'done' when finished)
   - Rating (1-5)
```

### Searching Recipes

```
By Ingredient:
1. Select "Search by Ingredient"
2. Enter ingredient name
3. View matching recipes

By Rating:
1. Select "Search by Rating"
2. Enter minimum rating threshold
3. View recipes meeting or exceeding the threshold
```

## 💻 Technical Details

### OOP Concepts Implemented

- **Inheritance**: Recipe hierarchy with `RecipeBase` as parent class
- **Polymorphism**: Virtual display method implementation in derived classes
- **Encapsulation**: Private data members with public interfaces
- **Abstraction**: Abstract base class (`RecipeBase`) with pure virtual methods

### Data Management

- **Dynamic Memory**: Proper allocation and deallocation of recipe objects
- **STL Containers**: Vector implementation for collections
- **Algorithms**: Sorting and searching functionality
- **Exception Handling**: Input validation and error management

## 🔍 Code Highlights

```cpp
// Polymorphic display method
class RecipeBase {
public:
    virtual void display() const = 0; // Pure virtual method
    // ...
};

// Implementation in derived classes
void VegetarianRecipe::display() const override {
    cout << "Name: " << name << endl;
    // ...
}
```

```cpp
// Advanced search and sort
vector<RecipeBase*> getTopRatedRecipes(size_t topN) const {
    vector<RecipeBase*> sortedRecipes = recipes;
    sort(sortedRecipes.begin(), sortedRecipes.end(), [](RecipeBase* a, RecipeBase* b) {
        return a->getAverageRating() > b->getAverageRating();
    });
    // ...
}
```

## ⚙️ Future Enhancements

- Persistent storage using file I/O or database
- User authentication system
- Recipe categorization by cuisine type
- Advanced filtering options
- Nutritional information tracking
- Recipe scaling functionality
- Meal planning features


## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request


<p align="center">
  <sub>Built with ❤️ for culinary enthusiasts and developers alike</sub>
</p>

