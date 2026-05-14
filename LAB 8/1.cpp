#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// ================= COLORS =================
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ================= UI BOX =================
void printBox(string title) {
    cout << CYAN << "\n====================================\n";
    cout << "   " << title << endl;
    cout << "====================================\n" << RESET;
}

// ERROR
void printError(string msg) {
    cout << RED << msg << RESET << endl;
}

// SUCCESS
void printSuccess(string msg) {
    cout << GREEN << msg << RESET << endl;
}

// =====================================================
// POST CLASS
// =====================================================
class Post {
private:
    int id;
    string title;
    string category;
    int likes;
    bool recentlyLiked;

public:
    Post(int i, string t, string c)
        : id(i), title(t), category(c), likes(0), recentlyLiked(false) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getCategory() const { return category; }
    int getLikes() const { return likes; }
    bool isRecentlyLiked() const { return recentlyLiked; }

    void likePost() {
        likes++;
        recentlyLiked = true;
    }

    void resetRecent() {
        recentlyLiked = false;
    }

    void display() const {
        cout << CYAN << id << RESET << "\t"
             << title << "\t\t"
             << category << "\t\t"
             << GREEN << likes << RESET;
    }
};

// =====================================================
// USER CLASS
// =====================================================
class User {
private:
    string name;
    int age;
    vector<string> interests;

public:

    void createProfile() {
        printBox("CREATE PROFILE");

        while (true) {
            cout << "Enter Name: ";
            getline(cin, name);

            bool valid = true;
            for (char c : name) {
                if (isdigit(c)) valid = false;
            }

            if (!valid || name.empty()) {
                printError("INVALID INPUT! ENTER NAME ONLY (NO NUMBERS)");
            } else break;
        }

        while (true) {
            cout << "Enter Age: ";

            if (!(cin >> age)) {
                printError("INVALID INPUT! ENTER ONLY NUMBER");
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }
    }

    void addInterests() {
        int n;

        while (true) {
            cout << "How many interests? ";

            if (!(cin >> n)) {
                printError("INVALID INPUT! ENTER ONLY NUMBER");
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        cin.ignore();

        for (int i = 0; i < n; i++) {

            string interest;

            while (true) {
                cout << "Enter interest " << i + 1 << ": ";
                getline(cin, interest);

                bool valid = true;
                for (char c : interest) {
                    if (isdigit(c)) valid = false;
                }

                if (!valid || interest.empty()) {
                    printError("INVALID INPUT! NO NUMBERS ALLOWED");
                } else break;
            }

            interests.push_back(interest);
        }
    }

    string getName() { return name; }
    vector<string> getInterests() { return interests; }

    void showProfile() {
        printBox("USER PROFILE");

        cout << "Name: " << GREEN << name << RESET << endl;
        cout << "Age: " << age << endl;

        cout << "Interests: ";
        for (auto &i : interests)
            cout << YELLOW << i << " " << RESET;
        cout << endl;
    }
};

// =====================================================
// FEED ENGINE
// =====================================================
class FeedEngine {

public:

    bool isInterest(User &user, Post &post) {
        for (string i : user.getInterests()) {
            if (i == post.getCategory())
                return true;
        }
        return false;
    }

    void showAllPosts(User &user, vector<Post> &posts) {
        printBox("ALL POSTS");

        cout << "ID\tTitle\t\tCategory\tLikes\n";
        cout << "--------------------------------------------------\n";

        for (auto &p : posts) {
            p.display();

            if (isInterest(user, p)) {
                cout << YELLOW << "  ✔ MATCHES YOUR INTEREST" << RESET;
            }

            cout << endl;
        }
    }

    void showFeed(vector<Post> &posts, string userName) {
        printBox("YOUR FEED");

        cout << "Hello " << GREEN << userName << RESET << "!\n";

        bool found = false;

        for (auto &p : posts) {
            if (p.isRecentlyLiked()) {
                p.display();
                cout << YELLOW << "  -> (RECENTLY LIKED!)" << RESET << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No recently liked posts.\n";
        }
    }

    void showRecommendations(User &user, vector<Post> &posts) {
        printBox("RECOMMENDED FOR YOU 🔥");

        bool found = false;

        for (auto &p : posts) {
            if (isInterest(user, p)) {
                p.display();
                cout << YELLOW << "  -> (BASED ON YOUR INTEREST)" << RESET << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No recommendations available.\n";
        }
    }

    void showTopPosts(vector<Post> &posts) {
        printBox("TOP TRENDING POSTS 🏆");

        for (int i = 0; i < posts.size(); i++) {
            for (int j = i + 1; j < posts.size(); j++) {
                if (posts[j].getLikes() > posts[i].getLikes()) {
                    swap(posts[i], posts[j]);
                }
            }
        }

        for (int i = 0; i < 5 && i < posts.size(); i++) {
            posts[i].display();
            cout << endl;
        }
    }
};

// =====================================================
// MAIN
// =====================================================
int main() {

    User user;
    FeedEngine engine;

    vector<Post> posts;

    posts.push_back(Post(1, "Football Highlights", "Sports"));
    posts.push_back(Post(2, "AI Revolution", "Technology"));
    posts.push_back(Post(3, "Makeup Tutorial", "Makeup"));
    posts.push_back(Post(4, "Beauty Skincare Routine", "Beauty"));
    posts.push_back(Post(5, "Study Tips", "Education"));
    posts.push_back(Post(6, "Healthy Diet", "Health"));
    posts.push_back(Post(7, "Gym Workout", "Fitness"));
    posts.push_back(Post(8, "Travel Vlog", "Travel"));
    posts.push_back(Post(9, "Coding Basics", "Technology"));
    posts.push_back(Post(10, "Fashion Trends", "Fashion"));
    posts.push_back(Post(11, "Gaming Review", "Gaming"));
    posts.push_back(Post(12, "Science Facts", "Education"));
    posts.push_back(Post(13, "News Update", "News"));

    cin.ignore(1000, '\n');

    user.createProfile();
    user.addInterests();

    int choice;

    while (true) {

        printBox("MAIN MENU");

        cout << "1. View Profile\n";
        cout << "2. View All Posts\n";
        cout << "3. Like a Post\n";
        cout << "4. Show My Feed\n";
        cout << "5. Recommended Posts 🔥\n";
        cout << "6. Top Trending Posts 🏆\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            printError("INVALID INPUT! ENTER NUMBER 1-7");
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            user.showProfile();
        }

        else if (choice == 2) {
            engine.showAllPosts(user, posts);
        }

        else if (choice == 3) {

            int id;
            cout << "Enter Post ID: ";

            if (!(cin >> id)) {
                printError("INVALID INPUT!");
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            bool found = false;

            for (auto &p : posts) {
                if (p.getId() == id) {
                    p.likePost();
                    printSuccess("Post Liked!");
                    found = true;
                } else {
                    p.resetRecent();
                }
            }

            if (!found) {
                printError("Invalid Post ID!");
            }
        }

        else if (choice == 4) {
            engine.showFeed(posts, user.getName());
        }

        else if (choice == 5) {
            engine.showRecommendations(user, posts);
        }

        else if (choice == 6) {
            engine.showTopPosts(posts);
        }

        else if (choice == 7) {
            cout << GREEN << "Exiting Program...\n" << RESET;
            break;
        }

        else {
            printError("INVALID CHOICE!");
        }
    }

    return 0;
}