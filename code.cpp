//Code for implementation in c++ using oops concepts 
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm> // For sorting

using namespace std;

class Ingredient {
public:
    string name;
    Ingredient(const string& n) : name(n) {}
};

class RecipeBase {
public:
    string name;
    string description;
    string category;
    vector<Ingredient> ingredients;
    vector<int> ratings;

    virtual ~RecipeBase() {}
    virtual void display() const = 0;
    virtual double getAverageRating() const {
        if (ratings.empty()) return 0.0;
        double sum = 0.0;
        for (int rating : ratings) {
            sum += rating;
        }
        return sum / ratings.size();
    }
    virtual void addRating(int rating) {
        if (rating >= 1 && rating <= 5) {
            ratings.push_back(rating);
        } else {
            throw invalid_argument("Invalid rating. Rating should be between 1 and 5.");
        }
    }
    bool containsIngredient(const string& ingredientName) const {
        for (const Ingredient& ingredient : ingredients) {
            if (ingredient.name == ingredientName) {
                return true;
            }
        }
        return false;
    }
    void displayRatings() const {
        cout << "Ratings: ";
        for (int rating : ratings) {
            cout << rating << " ";
        }
        cout << endl;
    }
};

class VegetarianRecipe : public RecipeBase {
public:
    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Category: " << category << endl;
        cout << "Ingredients: ";
        for (const Ingredient& ingredient : ingredients) {
            cout << ingredient.name << ", ";
        }
        cout << endl;
        displayRatings();
    }
};

class NonVegetarianRecipe : public RecipeBase {
public:
    void display() const override {

        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Category: " << category << endl;
        cout << "Ingredients: ";
        for (const Ingredient& ingredient : ingredients) {
            cout << ingredient.name << ", ";
        }
        cout << endl;
        displayRatings();
    }
};

class User {
private:
    string name;
    vector<Ingredient> preferredIngredients;
    vector<RecipeBase*> favoriteRecipes;
    vector<RecipeBase*> submittedRecipes;

public:
    User(const string& n) : name(n) {}

    void addPreferredIngredient(const Ingredient& ingredient) {
        preferredIngredients.push_back(ingredient);
    }

    void addFavoriteRecipe(RecipeBase* recipe) {
        if (recipe) {
            favoriteRecipes.push_back(recipe);
        } else {
            throw invalid_argument("Recipe is null.");
        }
    }

    void addSubmittedRecipe(RecipeBase* recipe) {
        if (recipe) {
            submittedRecipes.push_back(recipe);
        } else {
            throw invalid_argument("Recipe is null.");
        }
    }

    void displaySubmittedRecipes() const {
        cout << "Submitted Recipes:" << endl;
        for (const RecipeBase* recipe : submittedRecipes) {
            recipe->display();
        }
    }
};

class RecipeManager {
private:
    vector<RecipeBase*> recipes;

public:
    ~RecipeManager() {
        for (RecipeBase* recipe : recipes) {
            delete recipe;
        }
    }

    void addRecipe(RecipeBase* recipe) {
        if (recipe) {
            recipes.push_back(recipe);
        } else {
            throw invalid_argument("Recipe is null.");
        }
    }

    void removeRecipe(const string& recipeName) {
        auto it = remove_if(recipes.begin(), recipes.end(), [&recipeName](RecipeBase* recipe) {
            return recipe->name == recipeName;
        });
        if (it != recipes.end()) {
            delete *it;
            recipes.erase(it, recipes.end());
            cout << "Recipe removed successfully." << endl;
        } else {
            cout << "Recipe not found." << endl;
        }
    }

    vector<RecipeBase*> searchByIngredient(const string& ingredientName) const {
        vector<RecipeBase*> result;
        for (RecipeBase* recipe : recipes) {
            if (recipe->containsIngredient(ingredientName)) {
                result.push_back(recipe);
            }
        }
        return result;
    }

    vector<RecipeBase*> searchByName(const string& recipeName) const {
        vector<RecipeBase*> result;
        for (RecipeBase* recipe : recipes) {
            if (recipe->name == recipeName) {
                result.push_back(recipe);
            }
        }
        return result;
    }

    vector<RecipeBase*> searchByRating(double minRating) const {
        vector<RecipeBase*> result;
        for (RecipeBase* recipe : recipes) {
            if (recipe->getAverageRating() >= minRating) {
                result.push_back(recipe);
            }
        }
        return result;
    }

    void displayAllRecipes() const {
        cout<<"\n-------------------------------------------------------------\n";
        cout << "All Recipes:" << endl;
        for (const RecipeBase* recipe : recipes) {
            recipe->display();
        cout<<"\n-------------------------------------------------------------\n";
        }
    }

    vector<RecipeBase*> getTopRatedRecipes(size_t topN) const {
        vector<RecipeBase*> sortedRecipes = recipes;
        sort(sortedRecipes.begin(), sortedRecipes.end(), [](RecipeBase* a, RecipeBase* b) {
            return a->getAverageRating() > b->getAverageRating();
        });
        if (sortedRecipes.size() > topN) {
            sortedRecipes.resize(topN);
        }
        return sortedRecipes;
    }
};

void getUserInputForRecipe(RecipeBase* recipe) {
    cout<<"\n-------------------------------------------------------------\n";
    cout << "Enter recipe name: ";
    getline(cin, recipe->name);
    cout << "Enter description: ";
    getline(cin, recipe->description);
    cout << "Enter category: ";
    getline(cin, recipe->category);
    cout << "Enter ingredients (one per line, enter 'done' to finish):" << endl;
    string ingredientName;

    while (true) {
        getline(cin, ingredientName);
        if (ingredientName == "done") break;
        recipe->ingredients.push_back(Ingredient(ingredientName));
    }
    cout << "Enter ratings for the recipe (1 to 5): ";
    int rating;
    cin >> rating;
    recipe->addRating(rating);
    cout<<"\n-------------------------------------------------------------\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addRecipe(RecipeManager& manager) {
    cout<<"\n-------------------------------------------------------------\n";
    cout << "Enter details for a new recipe:" << endl;
    cout << "1. Add Vegetarian Recipe" << endl;
    cout << "2. Add Non-Vegetarian Recipe" << endl;
    cout<<"\n-------------------------------------------------------------\n";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        VegetarianRecipe* vegRecipe = new VegetarianRecipe();
        getUserInputForRecipe(vegRecipe);
        manager.addRecipe(vegRecipe);
    } else if (choice == 2) {
        NonVegetarianRecipe* nonVegRecipe = new NonVegetarianRecipe();
        getUserInputForRecipe(nonVegRecipe);
        manager.addRecipe(nonVegRecipe);
    } else {
        cout << "Invalid choice. Recipe not added." << endl;
    }
}

void searchRecipesByIngredient(const RecipeManager& manager) {
    cout << "Enter ingredient name to search for: ";
    string ingredientName;
    getline(cin, ingredientName);
    vector<RecipeBase*> searchResult = manager.searchByIngredient(ingredientName);
    if (searchResult.empty()) {
        cout << "No recipes found containing " << ingredientName << "." << endl;
    } else {
        cout << "Recipes containing " << ingredientName << ":" << endl;
        for (RecipeBase* recipe : searchResult) {
            recipe->display();
        }
    }
}

void searchRecipesByRating(const RecipeManager& manager) {
    cout << "Enter minimum rating to search for: ";
    double minRating;
    cin >> minRating;
    cin.ignore();
    vector<RecipeBase*> searchResult = manager.searchByRating(minRating);
    if (searchResult.empty()) {
        cout << "No recipes found with an average rating of " << minRating << " or higher." << endl;
    } else {
        cout << "Recipes with an average rating of " << minRating << " or higher:" << endl;
        for (RecipeBase* recipe : searchResult) {
            recipe->display();
        }
    }
}

void viewAllRecipes(const RecipeManager& manager) {
    manager.displayAllRecipes();
}

void removeRecipe(RecipeManager& manager) {
    cout<<"\n-------------------------------------------------------------\n";
    cout << "Enter the name of the recipe to remove: ";
    cout<<"\n-------------------------------------------------------------\n";
    string recipeName;
    getline(cin, recipeName);
    manager.removeRecipe(recipeName);
}

void displayTopRatedRecipes(const RecipeManager& manager) {
    cout<<"\n-------------------------------------------------------------\n";
    cout << "Enter the number of top rated recipes to display: ";
    cout<<"\n-------------------------------------------------------------\n";
    size_t topN;
    cin >> topN;
    cin.ignore();
    vector<RecipeBase*> topRecipes = manager.getTopRatedRecipes(topN);
    if (topRecipes.empty()) {
        cout << "No recipes available." << endl;
    } else {
        cout << "Top " << topN << " rated recipes:" << endl;
        for (RecipeBase* recipe : topRecipes) {
            recipe->display();
        }
    }
}

int main() {
    RecipeManager manager;
    try {
        while (true) {
            cout<<"\n-------------------------------------------------------------\n";
            cout <<"\t\t Menu " << endl;
            cout<<"\n-------------------------------------------------------------\n";
            cout << "\t1. Add Recipe" << endl;
            cout << "\t2. Search by Ingredient" << endl;
            cout << "\t3. Search by Rating" << endl;
            cout << "\t4. View All Recipes" << endl;
            cout << "\t5. Remove Recipe" << endl;
            cout << "\t6. Display Top Rated Recipes" << endl;
            cout << "\t7. Exit" << endl;
            cout<<"\n-------------------------------------------------------------\n";
            int option;
            cin >> option;
            cin.ignore();
            switch (option) {
                case 1:
                    addRecipe(manager);
                    break;
                case 2:
                    searchRecipesByIngredient(manager);
                    break;
                case 3:
                    searchRecipesByRating(manager);
                    break;
                case 4:
                    viewAllRecipes(manager);
                    break;
                case 5:
                    removeRecipe(manager);
                    break;
                case 6:
                    displayTopRatedRecipes(manager);
                    break;
                case 7:
                    cout << "Exiting program." << endl;
                    return 0;
                default:
                    cout<<"\n-------------------------------------------------------------\n";
                    cout << "Invalid option. Please choose again." << endl;
                    cout<<"\n-------------------------------------------------------------\n";
            }
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
