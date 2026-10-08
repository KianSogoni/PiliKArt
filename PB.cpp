#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// ─── CONSTANTS ────────────────────────────────────────────────────────────────
const int MAX_FAQ = 200;
const int MAX_KEYWORDS = 15;
const int MAX_PHRASES = 10;
const int MAX_RESPONSE = 2000;
const int max_name = 50;
const int max_input = 500;

// PRODUCT DATA STRUCTS──────────────────────────────────────────────────────────────── 
// ----- CLOTHING (HABI ) ────────────────────────────────────────────────────────────────
struct ClothingItem {
    char name[50];
    char sizes[5][10];
    int sizeCount;
    char colors[5][20];
    int colorCount;
    float price;
    int stock;
};

ClothingItem habiItems[] = {
    {"1 pair bikini XL limited", {"XL"}, 1, {"Black", "Pink", "Blue"}, 3, 3000, 10},
    {"Fitted shirt S", {"S"}, 1, {"White", "Black", "Navy"}, 3, 499, 25},
    {"Cargo pants 2XL", {"2XL"}, 1, {"Khaki", "Black", "Olive"}, 3, 649, 15},
    {"Crop top Gnarly limited", {"S", "M", "L"}, 3, {"Black", "White", "Red"}, 3, 2500, 8},
    {"Long sleeve Chenal", {"S", "M", "L", "XL"}, 4, {"Beige", "Black", "Navy"}, 3, 500, 20},
    {"Rip denim jeans M", {"M"}, 1, {"Blue", "Black"}, 2, 1250, 12},
    {"Lakers Hoodie L limited", {"L"}, 1, {"Purple", "Yellow", "Black"}, 3, 7500, 5},
    {"Corduroy jeans L", {"L"}, 1, {"Brown", "Beige", "Black"}, 3, 500, 18},
    {"Black & white tuxedo XL", {"XL"}, 1, {"Black/White"}, 1, 5000, 3},
    {"Polo shirt XL", {"XL"}, 1, {"White", "Blue", "Black"}, 3, 350, 30},
    {"Jogging pants CCC exclusive", {"S", "M", "L", "XL", "XXL"}, 5, {"Gray", "Black", "Navy"}, 3, 500, 40},
    {"PE shirt CCC exclusive", {"S", "M", "L", "XL", "XXL"}, 5, {"White", "Blue", "Red"}, 3, 500, 35},
    {"Mini skirt XS", {"XS"}, 1, {"Black", "Plaid", "Denim Blue"}, 3, 200, 15},
    {"Maong pants XL", {"XL"}, 1, {"Blue", "Black"}, 2, 3000, 10},
    {"Leggings M", {"M"}, 1, {"Black", "Gray", "Navy"}, 3, 250, 25}
};
int habiItemCount = 15;

// ----- TECH (APOLLO) ────────────────────────────────────────────────────────────────
struct TechItem {
    char name[50];
    char specs[100];
    char colors[5][20];
    int colorCount;
    float price;
    int stock;
};

TechItem apolloItems[] = {
    {"USB Flash Drive (128GB)", "USB 3.0, 128GB Storage", {"Black", "Silver", "Blue", "Red"}, 4, 799, 50},
    {"Wireless Mouse", "2.4GHz, 1200 DPI, Silent Click", {"Black", "White", "Red", "Blue"}, 4, 420, 40},
    {"Mechanical Keyboard", "RGB Backlit, Blue Switches", {"Black", "White", "Pink"}, 3, 1750, 25},
    {"Bluetooth Earphones", "5.0 Bluetooth, 8hr Battery", {"Black", "White", "Blue"}, 3, 890, 35},
    {"Power Bank (10,000mAh)", "10,000mAh, Dual USB, Fast Charging", {"Black", "Silver", "Blue", "Pink"}, 4, 1499, 30},
    {"Gaming Headset", "7.1 Surround Sound, Noise Cancelling Mic", {"Black", "Red", "White"}, 3, 1650, 20},
    {"Smartwatch", "1.3\" Display, Heart Rate Monitor", {"Black", "Silver", "Rose Gold"}, 3, 2100, 15},
    {"Phone Stand", "Adjustable, Foldable, Non-slip", {"Black", "White", "Blue", "Pink"}, 4, 250, 60},
    {"USB Type-C Cable", "6ft Braided, Fast Charging", {"Black", "White", "Blue", "Red"}, 4, 150, 80},
    {"HDMI Cable (2m)", "4K Support, Gold-plated", {"Black"}, 1, 300, 45},
    {"Webcam (1080p)", "1080p HD, Built-in Mic, Auto Focus", {"Black"}, 1, 950, 18},
    {"LED Desk Lamp", "5 Brightness, 3 Color Modes", {"Black", "White", "Pink"}, 3, 600, 25},
    {"Portable Speaker", "10W, BT 5.0, 12hr Battery", {"Black", "Blue", "Red"}, 3, 700, 22},
    {"External Hard Drive (1TB)", "1TB, USB 3.0, Portable", {"Black", "Silver"}, 2, 3500, 12},
    {"Wireless Charger Pad", "15W Fast Charging, Qi Compatible", {"Black", "White"}, 2, 980, 28}
};
int apolloItemCount = 15;

// ----- FURNITURE (NIPA) ────────────────────────────────────────────────────────────────
struct FurnitureItem {
    char name[50];
    char dimensions[50];
    char materials[50];
    char colors[5][20];
    int colorCount;
    float price;
    int stock;
};

FurnitureItem nipaItems[] = {
    {"Bed Frame", "75x55x40 in", "Solid Wood", {"Brown", "White", "Black"}, 3, 5999.75, 8},
    {"Dining table set", "60x36x30 in", "Wood + Metal", {"Brown", "White", "Black"}, 3, 9999.75, 5},
    {"Couch set", "84x35x32 in", "Fabric + Wood", {"Gray", "Beige", "Blue", "Black"}, 4, 8999.75, 4},
    {"Refrigerator", "28x30x67 in", "Stainless Steel", {"Silver", "Black", "White"}, 3, 11000.50, 6},
    {"Portable vacuum cleaner", "10x8x20 in", "Plastic + Metal", {"Red", "Black", "White"}, 3, 4999.75, 12},
    {"Cabinets", "36x18x72 in", "Engineered Wood", {"Brown", "White", "Oak"}, 3, 1499.75, 10},
    {"Air conditioner", "20x12x14 in", "Plastic + Metal", {"White", "Silver"}, 2, 12999.75, 7},
    {"Comforter", "80x90 in", "Cotton + Polyester", {"White", "Gray", "Beige", "Navy"}, 4, 699.75, 20},
    {"Pillow", "20x28 in", "Cotton + Memory Foam", {"White", "Gray"}, 2, 399.99, 30},
    {"Vanity table with chair", "32x18x54 in", "Wood + Glass", {"White", "Black", "Pink"}, 3, 4967.99, 5}
};
int nipaItemCount = 10;

// ----- GROCERY (PASO) ────────────────────────────────────────────────────────────────
struct GroceryItem {
    char name[50];
    char category[30];
    char unit[20];
    float price;
    int stock;
};

GroceryItem pasoItems[] = {
    {"Water", "Beverages", "500ml bottle", 9.98, 200},
    {"Soda Pop (320ml)", "Beverages", "can", 38.45, 150},
    {"Milk Powder (150g)", "Dairy", "pack", 110.50, 80},
    {"Bread", "Bakery", "loaf", 20.25, 100},
    {"Pancit Canton (Kasalo Pack)", "Noodles", "pack", 20.50, 120},
    {"Chicken Noodles (100g)", "Noodles", "cup", 12.50, 180},
    {"Sardines", "Canned Goods", "can", 25.15, 200},
    {"Keso de Bola", "Dairy", "piece", 514.75, 30},
    {"Eggs (12pcs)", "Dairy", "tray", 118.00, 90},
    {"Cheddar Cheese (160g)", "Dairy", "pack", 56.50, 70},
    {"Chips (100g)", "Snacks", "pack", 45.75, 150},
    {"All purpose flour (400g)", "Baking", "pack", 52.25, 60},
    {"White Sugar (1kg)", "Baking", "pack", 77.85, 85},
    {"Penne Pasta (500g)", "Pasta", "pack", 97.65, 55},
    {"Tocino (250g)", "Meat", "pack", 120.00, 45}
};
int pasoItemCount = 15;

// ─── DATA STRUCTURE ──────────────────────────────────────────────────────────
struct FAQ {
    char keywords[MAX_KEYWORDS][max_name];
    int keywordCount;
    char phrases[MAX_PHRASES][max_name];
    int phraseCount;
    char response[MAX_RESPONSE];
};

// ─── KNOWLEDGE BASE ───────────────────────────────────────────────────
FAQ knowledgeBase[MAX_FAQ];
int knowledgeBaseSize = 0;

// ─── HELPER FUNCTIONS ─────────────────────────────────────────────────────────

void toLower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

bool contains(const char* haystack, const char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);
    if (nLen > hLen) return false;
    for (int i = 0; i <= hLen - nLen; i++) {
        bool match = true;
        for (int j = 0; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

bool matchesFAQ(const char* input, const FAQ& entry) {
    for (int i = 0; i < entry.phraseCount; i++) {
        if (contains(input, entry.phrases[i])) return true;
    }
    for (int i = 0; i < entry.keywordCount; i++) {
        if (contains(input, entry.keywords[i])) return true;
    }
    return false;
}

// ==================== HELPER FUNCTIONS FOR KNOWLEDGE BASE ====================

void addKeywords(FAQ& entry, const char* kwList[], int count) {
    entry.keywordCount = count;
    for (int i = 0; i < count; i++) {
        strcpy(entry.keywords[i], kwList[i]);
    }
}
void addPhrases(FAQ& entry, const char* phList[], int count) {
    entry.phraseCount = count;
    for (int i = 0; i < count; i++) {
        strcpy(entry.phrases[i], phList[i]);
    }
}
void addFAQ(FAQ& entry, const char* kwList[], int kwCount, 
            const char* phList[], int phCount, const char* response) {
    if (kwCount > 0) {
        addKeywords(entry, kwList, kwCount);
    } else {
        entry.keywordCount = 0;
    }
    if (phCount > 0) {
        addPhrases(entry, phList, phCount);
    } else {
        entry.phraseCount = 0;
    }
    strcpy(entry.response, response);
}

// PRODUCT SEARCH FUNCS────────────────────────────────────────────────────────────────
void searchClothing(const char* query) {
    bool found = false;
    char queryLower[100];
    strcpy(queryLower, query);
    toLower(queryLower);
    
    cout << "\n============================================================\n";
    cout << "                  HABI - ITEM FINDER                        \n";
    cout << "============================================================\n";
    
    for (int i = 0; i < habiItemCount; i++) {
        char itemLower[100];
        strcpy(itemLower, habiItems[i].name);
        toLower(itemLower);
        
        if (contains(itemLower, queryLower) || contains(queryLower, itemLower)) {
            cout << "\n  " << habiItems[i].name << "\n";
            cout << "  Price: PHP " << habiItems[i].price << "\n";
            cout << "  Sizes: ";
            for (int s = 0; s < habiItems[i].sizeCount; s++) {
                cout << habiItems[i].sizes[s];
                if (s < habiItems[i].sizeCount - 1) cout << ", ";
            }
            cout << "\n";
            cout << "  Colors: ";
            for (int c = 0; c < habiItems[i].colorCount; c++) {
                cout << habiItems[i].colors[c];
                if (c < habiItems[i].colorCount - 1) cout << ", ";
            }
            cout << "\n";
            cout << "  Stock: " << habiItems[i].stock << " units\n";
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\n  No clothing found matching \"" << query << "\"\n";
        cout << "============================================================\n";
    }
}

void searchTech(const char* query) {
    bool found = false;
    char queryLower[100];
    strcpy(queryLower, query);
    toLower(queryLower);
    
    cout << "\n============================================================\n";
    cout << "                  APOLLO - ITEM FINDER                          \n";
    cout << "============================================================\n";
    
    for (int i = 0; i < apolloItemCount; i++) {
        char itemLower[100];
        strcpy(itemLower, apolloItems[i].name);
        toLower(itemLower);
        
        if (contains(itemLower, queryLower) || contains(queryLower, itemLower)) {
            cout << "\n  " << apolloItems[i].name << "\n";
            cout << "  Price: PHP " << apolloItems[i].price << "\n";
            cout << "  Specs: " << apolloItems[i].specs << "\n";
            cout << "  Colors: ";
            for (int c = 0; c < apolloItems[i].colorCount; c++) {
                cout << apolloItems[i].colors[c];
                if (c < apolloItems[i].colorCount - 1) cout << ", ";
            }
            cout << "\n";
            cout << "  Stock: " << apolloItems[i].stock << " units\n";
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\n  No tech item found matching \"" << query << "\"\n";
        cout << "============================================================\n";
    }
}

void searchFurniture(const char* query) {
    bool found = false;
    char queryLower[100];
    strcpy(queryLower, query);
    toLower(queryLower);
    
    cout << "\n============================================================\n";
    cout << "                  NIPA - ITEM FINDER                       \n";
    cout << "============================================================\n";
    
    for (int i = 0; i < nipaItemCount; i++) {
        char itemLower[100];
        strcpy(itemLower, nipaItems[i].name);
        toLower(itemLower);
        
        if (contains(itemLower, queryLower) || contains(queryLower, itemLower)) {
            cout << "\n  " << nipaItems[i].name << "\n";
            cout << "  Price: PHP " << nipaItems[i].price << "\n";
            cout << "  Dimensions: " << nipaItems[i].dimensions << "\n";
            cout << "  Material: " << nipaItems[i].materials << "\n";
            cout << "  Colors: ";
            for (int c = 0; c < nipaItems[i].colorCount; c++) {
                cout << nipaItems[i].colors[c];
                if (c < nipaItems[i].colorCount - 1) cout << ", ";
            }
            cout << "\n";
            cout << "  Stock: " << nipaItems[i].stock << " units\n";
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\n  No furniture found matching \"" << query << "\"\n";
        cout << "============================================================\n";
    }
}

void searchGrocery(const char* query) {
    bool found = false;
    char queryLower[100];
    strcpy(queryLower, query);
    toLower(queryLower);
    
    cout << "\n============================================================\n";
    cout << "                  PASO - ITEM FINDER                         \n";
    cout << "============================================================\n";
    
    for (int i = 0; i < pasoItemCount; i++) {
        char itemLower[100];
        strcpy(itemLower, pasoItems[i].name);
        toLower(itemLower);
        
        if (contains(itemLower, queryLower) || contains(queryLower, itemLower)) {
            cout << "\n  " << pasoItems[i].name << "\n";
            cout << "  Category: " << pasoItems[i].category << "\n";
            cout << "  Price: PHP " << pasoItems[i].price << "\n";
            cout << "  Unit: " << pasoItems[i].unit << "\n";
            cout << "  Stock: " << pasoItems[i].stock << " units\n";
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\n  No grocery item found matching \"" << query << "\"\n";
        cout << "============================================================\n";
    }
}
// ============================================================================
// DISPLAY ALL FUNCTIONS (ADD THIS AFTER your search functions)
// ============================================================================

void displayAllClothes() {
    cout << "\n+==================================================================+\n";
    cout << "|                    HABI - CLOTHING COLLECTION                    |\n";
    cout << "+==================================================================+\n";
    cout << "|  # | Item                              | Size | Price           |\n";
    cout << "+------------------------------------------------------------------+\n";
    for (int i = 0; i < habiItemCount; i++) {
        cout << "|  " << (i+1);
        if ((i+1) < 10) cout << " ";
        cout << " | " << habiItems[i].name;
        int len = strlen(habiItems[i].name);
        for (int j = len; j < 33; j++) cout << " ";
        cout << "| ";
        // Display first available size
        if (habiItems[i].sizeCount > 0) {
            cout << habiItems[i].sizes[0];
            for (int j = strlen(habiItems[i].sizes[0]); j < 5; j++) cout << " ";
        } else {
            cout << "N/A   ";
        }
        cout << "| PHP " << habiItems[i].price;
        int priceLen = 0;
        float temp = habiItems[i].price;
        while (temp >= 1) { temp /= 10; priceLen++; }
        for (int j = 0; j < 8 - priceLen; j++) cout << " ";
        cout << "|\n";
    }
    cout << "+==================================================================+\n";
    cout << "|  Type an item name (e.g., 'bikini') for more details.           |\n";
    cout << "+==================================================================+\n";
}

void displayAllTech() {
    cout << "\n+==================================================================+\n";
    cout << "|                    APOLLO - TECH COLLECTION                      |\n";
    cout << "+==================================================================+\n";
    cout << "|  # | Item                              | Price                 |\n";
    cout << "+------------------------------------------------------------------+\n";
    for (int i = 0; i < apolloItemCount; i++) {
        cout << "|  " << (i+1);
        if ((i+1) < 10) cout << " ";
        cout << " | " << apolloItems[i].name;
        int len = strlen(apolloItems[i].name);
        for (int j = len; j < 33; j++) cout << " ";
        cout << "| PHP " << apolloItems[i].price;
        int priceLen = 0;
        float temp = apolloItems[i].price;
        while (temp >= 1) { temp /= 10; priceLen++; }
        for (int j = 0; j < 14 - priceLen; j++) cout << " ";
        cout << "|\n";
    }
    cout << "+==================================================================+\n";
    cout << "|  Type an item name (e.g., 'usb', 'mouse') for more details.     |\n";
    cout << "+==================================================================+\n";
}

void displayAllFurniture() {
    cout << "\n+==================================================================+\n";
    cout << "|                    NIPA - FURNITURE COLLECTION                   |\n";
    cout << "+==================================================================+\n";
    cout << "|  # | Item                              | Price                 |\n";
    cout << "+------------------------------------------------------------------+\n";
    for (int i = 0; i < nipaItemCount; i++) {
        cout << "|  " << (i+1);
        if ((i+1) < 10) cout << " ";
        cout << " | " << nipaItems[i].name;
        int len = strlen(nipaItems[i].name);
        for (int j = len; j < 33; j++) cout << " ";
        cout << "| PHP " << nipaItems[i].price;
        int priceLen = 0;
        float temp = nipaItems[i].price;
        while (temp >= 1) { temp /= 10; priceLen++; }
        for (int j = 0; j < 14 - priceLen; j++) cout << " ";
        cout << "|\n";
    }
    cout << "+==================================================================+\n";
    cout << "|  Type an item name (e.g., 'bed', 'couch') for more details.     |\n";
    cout << "+==================================================================+\n";
}

void displayAllGrocery() {
    cout << "\n+==================================================================+\n";
    cout << "|                    PASO - GROCERY COLLECTION                     |\n";
    cout << "+==================================================================+\n";
    cout << "|  # | Item                              | Category    | Price   |\n";
    cout << "+------------------------------------------------------------------+\n";
    for (int i = 0; i < pasoItemCount; i++) {
        cout << "|  " << (i+1);
        if ((i+1) < 10) cout << " ";
        cout << " | " << pasoItems[i].name;
        int len = strlen(pasoItems[i].name);
        for (int j = len; j < 33; j++) cout << " ";
        cout << "| " << pasoItems[i].category;
        for (int j = strlen(pasoItems[i].category); j < 11; j++) cout << " ";
        cout << "| PHP " << pasoItems[i].price;
        int priceLen = 0;
        float temp = pasoItems[i].price;
        while (temp >= 1) { temp /= 10; priceLen++; }
        for (int j = 0; j < 6 - priceLen; j++) cout << " ";
        cout << "|\n";
    }
    cout << "+==================================================================+\n";
    cout << "|  Type an item name (e.g., 'water', 'bread') for more details.    |\n";
    cout << "+==================================================================+\n";
}

// ==================== RESPONSES ====================

const char* menu = 
    "\n+==========================================================+\n"
    "|              PILIKart - CUSTOMER ASSISTANCE                |\n"
    "+============================================================+\n"
    "|              ---- OUR 4 DEPARTMENT STORES ----             |\n"
    "|  HABI (Fashion)    |  APOLLO (Tech)     |  NIPA (Home)     |\n"
    "|  Bikini, Shirts    |  USB, Mouse        |  Bed, Couch      |\n"
    "|  Pants, Jeans      |  Keyboard, Headset |  Table, Cabinet  |\n"
    "|  Hoodies, Skirts   |  Powerbank, Speaker|  Refrigerator    |\n"
    "|  Sizes & Colors    |  Specs & Colors    |  Dimensions      |\n"
    "|  ------------------|--------------------|------------------|\n"
    "|                    |  PASO (Grocery)    |                  |\n"
    "|                    |  Water, Bread      |                  |\n"
    "|                    |  Eggs, Sardines    |                  |\n"
    "|                    |  Noodles, Tocino   |                  |\n"
    "|                    |  Dairy, Snacks     |                  |\n"
    "| ========================================================== |\n"
    "|            ---- FREQUENTLY ASKED QUESTIONS ----            |\n"
    "|  STORE INFO: Hours | Location | Contact | Parking          |\n"
    "|  POLICIES: Price Match | Returns | Delivery | Senior/PWD   |\n"
    "|  PAYMENT: Cash | GCash | Maya | Credit/Debit               |\n"
    "|                                                            |\n"
    "|         ----------TRY THESE COMMANDS:----------            |\n"
    "|  'display clothes/ tech / furniture / grocery'             |\n"
    "|  -TO VIEW fashion items / electronics / home items / food  |\n"
    "|  'usb', 'bed', 'water' - TO SEARCH specific products       |\n"
    "|                                                            |\n"
    "|  Type 'exit' to leave.                                     |\n"
    "+============================================================+\n";

const char* hours = 
    "\n+==================================================================+\n"
    "|                         STORE OPERATING HOURS                     |\n"
    "+==================================================================+\n"
    "|  Monday - Saturday         8:00 AM - 9:00 PM                      |\n"
    "|  Sunday                    9:00 AM - 7:00 PM                      |\n"
    "|  Holidays                  Regular Operating Hours                |\n"
    "+==================================================================+\n";

const char* loc = 
    "\n+==================================================================+\n"
    "|                          STORE LOCATION                           |\n"
    "+==================================================================+\n"
    "|  Address:     123 CCC Street, Barangay San Isidro                 |\n"
    "|               Calamba City, Laguna 4027                           |\n"
    "|  Landmark:    Beside CCC View                                     |\n"
    "+==================================================================+\n";

const char* contact = 
    "\n+==================================================================+\n"
    "|                        CONTACT INFORMATION                        |\n"
    "+==================================================================+\n"
    "|  Telephone:    (049) 123-4567                                     |\n"
    "|  Mobile:       0967-123-4567                                      |\n"
    "|  Email:        customer.service@pilikart.com                      |\n"
    "|  Facebook:     @PILIKartOfficial                                  |\n"
    "+==================================================================+\n";

const char* parking = 
    "\n+==================================================================+\n"
    "|                          PARKING FACILITIES                       |\n"
    "+==================================================================+\n"
    "|  Standard Vehicles (Cars)    | 20 slots                           |\n"
    "|  Senior Citizen/PWD          | 2 slots                            |\n"
    "|  Motorcycles                 | 10 slots                           |\n"
    "|  All parking is FREE!                                             |\n"
    "+==================================================================+\n";

const char* prodguide = 
    "\n+==================================================================+\n"
    "|                      PRODUCT LOCATION GUIDE                       |\n"
    "+==================================================================+\n"
    "|  DEPARTMENT          | CATEGORY              | AISLE & SECTION    |\n"
    "+--------------------------------------------------------------------+\n"
    "|  HABI (Fashion)      | Clothing - All Items  | Floor 2, Section A |\n"
    "|                      | Fitting Rooms         | Floor 2, Section B |\n"
    "|                      | Sale Racks            | Floor 2, Section C |\n"
    "+--------------------------------------------------------------------+\n"
    "|  APOLLO (Tech)       | Gadgets & Electronics | Floor 1, Section A |\n"
    "|                      | Computer Accessories  | Floor 1, Section B |\n"
    "|                      | Audio & Speakers      | Floor 1, Section C |\n"
    "+--------------------------------------------------------------------+\n"
    "|  NIPA (Furniture)    | Bedroom & Bed Frames  | Floor 3, Section A |\n"
    "|                      | Living Room & Couch   | Floor 3, Section B |\n"
    "|                      | Kitchen & Dining      | Floor 3, Section C |\n"
    "|                      | Appliances            | Floor 3, Section D |\n"
    "+--------------------------------------------------------------------+\n"
    "|  PASO (Grocery)      | Dairy & Eggs          | Floor 1, Section D |\n"
    "|                      | Bread & Bakery        | Floor 1, Section E |\n"
    "|                      | Canned Goods          | Floor 1, Section F |\n"
    "|                      | Beverages & Drinks    | Floor 1, Section G |\n"
    "|                      | Noodles & Pasta       | Floor 1, Section H |\n"
    "|                      | Snacks & Chips        | Floor 1, Section I |\n"
    "|                      | Meat & Tocino         | Floor 1, Section J |\n"
    "|                      | Baking Essentials     | Floor 1, Section K |\n"
    "+-------------------------------------------------------------------+\n"
    "|  CUSTOMER SERVICE    | Returns & Exchanges   | Floor 1, Near Main |\n"
    "|                      | Loyalty Registration  | Entrance           |\n"
    "|                      | Lost & Found          |                    |\n"
    "+===================================================================+\n";

const char* fresh = 
    "\n+==================================================================+\n"
    "|                       FRESH ITEMS INFORMATION                     |\n"
    "+==================================================================+\n"
    "|  * Pandesal baked fresh at 6AM and 3PM daily                      |\n"
    "|  * Organic vegetables delivered every Tuesday and Friday          |\n"
    "|  * Free-range eggs from local farms                               |\n"
    "+==================================================================+\n";

const char* quality = 
    "\n+==================================================================+\n"
    "|                       QUALITY GUARANTEE                           |\n"
    "+==================================================================+\n"
    "|  * All products from DTI accredited suppliers                     |\n"
    "|  * Freshness inspected daily                                      |\n"
    "|  * Return within 7 days with receipt if unsatisfied               |\n"
    "+==================================================================+\n";

const char* priceM = 
    "\n+==================================================================+\n"
    "|                         PRICE MATCH POLICY                        |\n"
    "+==================================================================+\n"
    "|  * Show competitor ad, we match the price!                        |\n"
    "|  * Product must be identical                                      |\n"
    "|  * Item must be in stock                                          |\n"
    "+==================================================================+\n";

const char* special = 
    "\n+==================================================================+\n"
    "|                       SPECIAL ORDER REQUEST                       |\n"
    "+==================================================================+\n"
    "|  * Processing Time: 2-3 business days                             |\n"
    "|  * No additional fee                                              |\n"
    "|  * Call (049) 123-4567 to place order                             |\n"
    "+==================================================================+\n";

const char* loyalty = 
    "\n+==================================================================+\n"
    "|                       LOYALTY REWARDS PROGRAM                     |\n"
    "+==================================================================+\n"
    "|  * FREE to join!                                                  |\n"
    "|  * 1 point per Php 50 spent                                       |\n"
    "|  * 100 points = Php 50 off                                        |\n"
    "|  * Double points on birthday month!                               |\n"
    "+==================================================================+\n";

const char* payment = 
    "\n+==================================================================+\n"
    "|                       ACCEPTED PAYMENT METHODS                    |\n"
    "+==================================================================+\n"
    "|  Cash | GCash | Maya | Credit Card | Debit Card                   |\n"
    "|  Visa, Mastercard, JCB accepted                                   |\n"
    "+==================================================================+\n";

const char* delivery = 
    "\n+==================================================================+\n"
    "|                         DELIVERY SERVICE                          |\n"
    "+==================================================================+\n"
    "|  * Fee: Php 49 (FREE for orders Php 500+)                         |\n"
    "|  * Same-day: Order before 2PM                                      |\n"
    "|  * Coverage: Barangay San Isidro, Halang, Real, Barandal          |\n"
    "+==================================================================+\n";

const char* returns = 
    "\n+==================================================================+\n"
    "|                          RETURN POLICY                            |\n"
    "+==================================================================+\n"
    "|  * Returns accepted within 7 days with receipt                    |\n"
    "|  * Items must be unused                                           |\n"
    "|  * Spoiled items: immediate replacement                           |\n"
    "+==================================================================+\n";

const char* scan = 
    "\n+==================================================================+\n"
    "|                     PRICE SCANNING POLICY                         |\n"
    "+==================================================================+\n"
    "|  If item scans HIGHER than shelf label:                           |\n"
    "|  * You pay the LOWER price                                        |\n"
    "|  * Notify cashier immediately                                     |\n"
    "+==================================================================+\n";

const char* senior = 
    "\n+==================================================================+\n"
    "|                  SENIOR CITIZEN & PWD DISCOUNT                    |\n"
    "+==================================================================+\n"
    "|  * 20% discount + VAT exemption                                   |\n"
    "|  * Valid Senior Citizen ID or PWD Card required                   |\n"
    "|  * Available everyday!                                            |\n"
    "+==================================================================+\n";

const char* greet = 
    "\n+==================================================================+\n"
    "|  Good day and welcome to PILIKart!                                |\n"
    "|  How may I assist you today?                                      |\n"
    "+==================================================================+\n";

const char* thanks = 
    "\n+==================================================================+\n"
    "|  You are most welcome!                                            |\n"
    "|  Thank you for choosing PILIKart!                                 |\n"
    "+==================================================================+\n";

// ==================== EASTER EGGS ====================

const char* AAAA = 
    "\n+==================================================================+\n"
    "|  STOP SHOUTINGGG                                                  |\n"
    "|  Keep it professional Sir, We're in a Public Space!!              |\n"
    "+==================================================================+\n";

const char* sixseven = 
    "\n+==================================================================+\n"
    "|  SIXXX SEVENNNNN                                                  |\n"
    "|  (omg pls staaahhhp -__-)                                         |\n"
    "+==================================================================+\n";

const char* EASTER_12345 = 
    "\n+==================================================================+\n"
    "|  six sevennnnn!                                                   |\n"
    "|  (omg pls staaahhhp -__-)                                         |\n"
    "+==================================================================+\n";

const char* idk = 
    "\n+==================================================================+\n"
    "|  No worries! Here's what I can help with:                         |\n"
    "|  Hours, Location, Products, Prices, Discounts, Delivery,          |\n"
    "|  Returns, or type 'menu' for full list!                           |\n"
    "+==================================================================+\n";

const char* MOLife = 
    "\n+==================================================================+\n"
    "|  42! ...but also, shopping at PILIKart!                           |\n"
    "|  Need help finding something?                                     |\n"
    "+==================================================================+\n";

const char* skibidi= 
    "\n+==================================================================+\n"
    "|  toilet                                                          |\n"
    "|  (omg pls stop X_X) We're too old for this...                    |\n"
    "+==================================================================+\n";

const char* rizz= 
    "\n+==================================================================+\n"
    "|  Bro got that PILIKart rizz                                       |\n"
    "|  We got discounts, not rizz. Touch grass?                         |\n"
    "|  (what am I doing with my life..)                                 |\n"
    "+==================================================================+\n";

const char* gyatt= 
    "\n+==================================================================+\n"
    "|  GYATT DAYUM                                                      |\n"
    "|  Sir/Ma'am this is a grocery store... please contain yourself TT  |\n"
    "+==================================================================+\n";

const char* sigma = 
    "\n+==================================================================+\n"
    "|  Sigma male? More like SIGMA SALE ! :P                             |\n"
    "|  10% off every Wednesdays! and B1T1's on Fridays!!                 |\n"
    "+==================================================================+\n";

const char* sus = 
    "\n+==================================================================+\n"
    "|  AMONG yuss ??                                                    |\n"
    "|  Grabi, gan'to pala among yus, nakakatatot.                       |\n"
    "+==================================================================+\n";

const char* bruh = 
    "\n+==================================================================+\n"
    "|  BRUH. Just buy something already...                              |\n"
    "|  or at least ask a real question plz TT                           |\n"
    "+==================================================================+\n";

const char* sheesh = 
    "\n+==================================================================+\n"
    "|  SHEEEEEESH                                                        |\n"
    "|  That's a lot of groceries! Need a bigger cart?                    |\n"
    "+==================================================================+\n";

const char* lodi = 
    "\n+==================================================================+\n"
    "|  HEY LODICAKES! Here's a virtual high five!                       |\n"
    "|  Need help with anything?                                         |\n"
    "+==================================================================+\n";

const char* charot= 
    "\n+==================================================================+\n"
    "|  Charot? 'wag mo akong chinacharot-charot ha,                     |\n"
    "|  nagttrabaho ng ayos 'yung tao dito oh...                         |\n"
    "+==================================================================+\n";

const char* luh= 
    "\n+====================================================================+\n"
    "|  LUH? Nagulat ka? Komedya na 'yan sa inyo? KIDDING                  |\n"
    "| Talagang mapapa-'luh' ka nalang talaga sa murang prices @ PiliKArt! |\n"
    "+====================================================================+\n";

const char* pak= 
    "\n+==================================================================+\n"
    "|  PAK! aray mo pakak! mauubos na ang fresh pandesal around 9AM!    |\n"
    "+==================================================================+\n";

const char* wifi= 
    "\n+==================================================================+\n"
    "|  FREE WiFi Available!                                             |\n"
    "|  Network: PILIKart_FreeWiFi                                       |\n"
    "|  Password: shopatpilikart                                         |\n"
    "+==================================================================+\n";

const char* cr= 
    "\n+==================================================================+\n"
    "|  COMFORT ROOM LOCATION                                            |\n"
    "|  Ground Floor: Near Customer Service                              |\n"
    "|  Second Floor: Left side near elevators                           |\n"
    "+==================================================================+\n";

const char* student= 
    "\n+==================================================================+\n"
    "|  STUDENT DISCOUNT                                                 |\n"
    "|  10% off every TUESDAY with valid school ID!                      |\n"
    "+==================================================================+\n";

const char* ayaw = 
    "\n+==================================================================+\n"
    "|  Huwag kang susuko pookie!                                       |\n"
    "|  Anong kailangan mo? We're here to help you!                     |\n"
    "+==================================================================+\n";

const char* sana= 
    "\n+==================================================================+\n"
    "|  Sana all may discount! But good news - everyone gets our        |\n"
    "|  great prices!                                                   |\n"
    "+==================================================================+\n";

const char* fanum= 
    "\n+==================================================================+\n"
    "|  Fanum tax?? nah, we don't tax here, we DISCOUNT!              |\n"
    "|  10% off on Wednesdays, and Buy 1, Take 1's on Fridays!        |\n"
    "+==================================================================+\n";

const char* alpha = 
    "\n+==================================================================+\n"
    "|  Alpha males? Nah, we only have DELTA - as in DEaLs, ano  TAra? |\n"
    "|  Get 10% off! on Wednesdays and 50% off on Fridays!             |\n"
    "+==================================================================+\n";

const char* nocap = 
    "\n+==================================================================+\n"
    "|  No cap? We accept all caps ACTUALLY.                            |\n"
    "|  Bring your bottles for recycling! For a more eco-pinas!         |\n"
    "+==================================================================+\n";

const char* bet = 
    "\n+==================================================================+\n"
    "|  BET! I'll hold you to that.                                   |\n"
    "|  Come shop at PILIKart or else... (jk pls come)             |\n"
    "+==================================================================+\n";

const char* yeet = 
    "\n+==================================================================+\n"
    "|  YEET your groceries into the cart! But gently...              |\n"
    "|  we don't want broken eggs :<<                                 |\n"
    "+==================================================================+\n";

const char* fr = 
    "\n+==================================================================+\n"
    "|  FR FR no cap on God?                                          |\n"
    "|  PiliKArt is the best dept store in the world!                 |\n"
    "+==================================================================+\n";

const char* ratio = 
    "\n+==================================================================+\n"
    "|  Ratio + L + didn't ask + touch grass + stay mad + cope harder  |\n"
    "+==================================================================+\n";

const char* cope = 
    "\n+==================================================================+\n"
    "|  Cope? Seethe? Mald?                                           |\n"
    "|  We have FREE AIR CONDITIONING! Cool down                      |\n"
    "|  Also, ICE CREAM! for just 35 Pesos!                           |\n"
    "+==================================================================+\n";

const char* based = 
    "\n+==================================================================+\n"
    "|  BASED? Heck yea we are, based on WHAT?                        |\n"
    "|  Based on our LOWEST PRICES in Calamba!                        |\n"
    "+==================================================================+\n";

const char* cringe = 
    "\n+==================================================================+\n"
    "|  CRINGE? Your MOM is cringe.                                   |\n"
    "|  Our PRICES are based. Get rekt                                |\n"
    "+==================================================================+\n";

const char* mid = 
    "\n+==================================================================+\n"
    "|  MID?? Our PANDESAL is FRESH daily at 6AM.                     |\n"
    "|  Nothing mid here sir, fyi!                                     |\n"
    "+==================================================================+\n";

const char* bussin = 
    "\n+==================================================================+\n"
    "|  BUSSIN?? Our pandesal is BUSSIN fr fr no cap.                 |\n"
    "|  6AM daily come get it, before it runs out!                    |\n"
    "+==================================================================+\n";

const char* slay = 
    "\n+==================================================================+\n"
    "|  SLAY Queen? We have QUEEN size sanitary napkins at Aisle 7!     |\n"
    "|  Period products at Aisle 7, Section C! Stay fresh bestie        |\n"
    "+==================================================================+\n";

const char* manager = 
    "\n+==================================================================+\n"
    "|  Our Manager Maria Works at Floor 1, Aisle 3!                   |\n"
    "|  Kindly tell her your concerns!                                 |\n"
    "+==================================================================+\n";

const char* mainchar = 
    "\n+==================================================================+\n"
    "|  Main character energy? Of course!                             |\n"
    "|  Get that FREE DELIVERY on 500php+ orders!                       |\n"
    "+==================================================================+\n";

const char* pov = 
    "\n+==================================================================+\n"
    "|  POV: You're reading this instead of buying groceries.         |\n"
    "|  Get your KArt filled now!                                     |\n"
    "+==================================================================+\n";

const char* npc = 
    "\n+==================================================================+\n"
    "|  NPC? I'm a Chatbot. with no personality. Hence,               |\n"
    "|  Type 'menu' or perish.                                        |\n"
    "+==================================================================+\n";

const char* ediwow = 
    "\n+==================================================================+\n"
    "|  EDI WOW! Wow na wow sa DISCOUNTS namin!                        |\n"
    "|  Senior/PWD 20% off everyday!                                   |\n"
    "+==================================================================+\n";

const char* chika = 
    "\n+==================================================================+\n"
    "|  Chika? Spill the tea? We have MILK TEA at Aisle 5!            |\n"
    "|  Say Hi to Cathy (our barista) for us!                         |\n"
    "+==================================================================+\n";

const char* melt = 
    "\n+==================================================================+\n"
    "|  Melting? Same. Cool yourself with our refreshing-              |\n"
    "|  Ice cream and Halo-halo at Aisle 3!                            |\n"
    "+==================================================================+\n";

const char* sup = 
    "\n+==================================================================+\n"
    "|  Not much, just helping customers!                             |\n"
    "|  What can I do for you?                                        |\n"
    "+==================================================================+\n";

const char* howru = 
    "\n+==================================================================+\n"
    "|  I'm great, thank you for asking!                              |\n"
    "|  How can I assist you today?                                   |\n"
    "+==================================================================+\n";

const char* sanasecret = 
    "\n+==================================================================+\n"
    "|  Our secret item: 'PILIKart Special Combo'                     |\n"
    "|  Ask any cashier! (Shh, don't tell anyone!)                    |\n"
    "+==================================================================+\n";

const char* rickroll = 
    "\n+==================================================================+\n"
    "|  Never gonna give you up, never gonna let you down!            |\n"
    "|  ...But we WILL give you discounts!                            |\n"
    "+==================================================================+\n";

const char* otw = 
    "\n+==================================================================+\n"
    "|  On the way? Perfect!                                          |\n"
    "|  We'll keep the pandesal warm for you!                         |\n"
    "+==================================================================+\n";

const char* petmalu = 
    "\n+==================================================================+\n"
    "|  PETMALU ka rin!                                               |\n"
    "|  Thanks for shopping at PILIKart!                              |\n"
    "+==================================================================+\n";

const char* kunomi = 
    "\n+==================================================================+\n"
    "|  --KUNOMI CODE ACTIVATED!--                                      |\n"
    "|  You found the secret cheat code!                                |\n"
    "|                                                                  |\n"
    "|  REWARD: 10% OFF your next purchase!                             |\n"
    "|  (Present this message at checkout)                              |\n"
    "|                                                                  |\n"
    "|  Virtual high five!                                              |\n"
    "+==================================================================+\n";

const char* gamemodeC = 
    "\n+==================================================================+\n"
    "|  Creative mode? Sir this is REALITY mode.                       |\n"
    "|  But don't fret! No cheats needed, because of our low prices!   |\n"
    "+==================================================================+\n";

const char* kill = 
    "\n+==================================================================+\n"
    "|  Nooooo! Don't '/kill'! We need customers!                     |\n"
    "|  Here's a FREE pandesal  (metaphorically)                      |\n"
    "+==================================================================+\n";

const char* milk = 
    "\n+==================================================================+\n"
    "|  Fresh Milk (1L) - 89php                                          |\n"
    "|  Magnolia Choco Milk - 45php                                      |\n"
    "|  Yogurt Drink - 25php                                             |\n"
    "|  All at Aisle 1, Section A!                                       |\n"
    "+==================================================================+\n";

const char* bread = 
    "\n+==================================================================+\n"
    "|  Pandesal (10pcs) - 25php                                        |\n"
    "|  Gardenia Wheat Bread - 70php                                    |\n"
    "|  Spanish Bread (5pcs) - 40php                                    |\n"
    "|  Fresh baked at 6AM and 3PM daily!                               |\n"
    "+==================================================================+\n";

const char* rice = 
    "\n+==================================================================+\n"
    "|  Sinandomeng Rice (5kg) - 265php                                 |\n"
    "|  Also available: Jasmine, Brown, and Premium variants!           |\n"
    "|  Located at Aisle 1, Section C                                   |\n"
    "+==================================================================+\n";

const char* eggs = 
    "\n+==================================================================+\n"
    "|  Eggs (1 tray/30pcs) - 210php                                    |\n"
    "|  Free-range eggs (1 dozen) - 150php                              |\n"
    "|  Located at Aisle 1, Section B                                   |\n"
    "+==================================================================+\n";

const char* chicken = 
    "\n+==================================================================+\n"
    "|  Chicken Breast (1kg) - 220php                                     |\n"
    "|  Whole Chicken - 180php/kg                                         |\n"
    "|  Chicken Wings (1kg) - 150php                                      |\n"
    "|  Fresh daily at Aisle 4, Section A!                              |\n"
    "+==================================================================+\n";

const char* pork = 
    "\n+==================================================================+\n"
    "|  Pork Belly (1kg) - 320php                                         |\n"
    "|  Ground Pork (500g) - 140php                                       |\n"
    "|  Pork Chop (1kg) - 280php                                          |\n"
    "|  Fresh daily at Aisle 4, Section A!                              |\n"
    "+==================================================================+\n";

const char* coke = 
    "\n+==================================================================+\n"
    "|  Coca-Cola 1.5L - 65php                                          |\n"
    "|  Coca-Cola 1L - 50php                                            |\n"
    "|  Coca-Cola Can (330ml) - 22php                                   |\n"
    "|  Located at Aisle 5, Section A!                                  |\n"
    "+==================================================================+\n";

const char* coffee= 
    "\n+==================================================================+\n"
    "|  Nescafe Classic (100g) - 135php                                 |\n"
    "|  Nescafe 3-in-1 (10 packs) - 85php                               |\n"
    "|  Kopiko Black (10 packs) - 75php                                 |\n"
    "|  Located at Aisle 5, Section B!                                  |\n"
    "+==================================================================+\n";

const char* cornedBeef = 
    "\n+==================================================================+\n"
    "|  Canned Corned Beef (regular) - 45php                             |\n"
    "|  Premium Corned Beef - 65php                                      |\n"
    "|  Located at Aisle 1, Section C!                                   |\n"
    "+==================================================================+\n";

const char* sardines = 
    "\n+==================================================================+\n"
    "|  Canned Sardines (regular) - 22php                                |\n"
    "|  Spanish Style Sardines - 28php                                   |\n"
    "|  Located at Aisle 1, Section C!                                   |\n"
    "+==================================================================+\n";

// ==================== GENERAL SALES & PROMO INQUIRIES ====================

const char* generalSaleResponse = 
    "+==================================================================+\n"
    "|  PILIKart REGULAR DISCOUNTS & PROMOS                             |\n"
    "+==================================================================+\n"
    "|  * Senior/PWD: 20% off everyday                                  |\n"
    "|  * Student: 10% off every Tuesday                                |\n"
    "|  * Payday Sale: 10% off every 15th & 30th                        |\n"
    "|  * Loyalty: 100 points = P50 off                                 |\n"
    "|                                                                  |\n"
    "|  For specific seasonal sales, ask about:                         |\n"
    "|  - May 3 (Foundation Day)                                        |\n"
    "|  - 11.11 (November 11)                                           |\n"
    "|  - 12.12 (December 12)                                           |\n"
    "|  - Back to School (May-June)                                     |\n"
    "|  - Black Friday (November)                                       |\n"
    "+==================================================================+\n";

// ==================== SALES & HOLIDAY RESPONSES ====================

const char* foundationResponse = 
    "+==================================================================+\n"
    "|  PILIKart FOUNDATION DAY SALE - MAY 3!                           |\n"
    "|  20% OFF on ALL items. FREE delivery. DOUBLE loyalty points.    |\n"
    "|  Valid: May 3 only. Thank you for 5 wonderful years!            |\n"
    "+==================================================================+\n";

const char* elevenResponse = 
    "+==================================================================+\n"
    "|  11.11 SUPER SALE - NOVEMBER 11!                                 |\n"
    "|  11% OFF storewide. Buy 1 Get 1 on selected items.              |\n"
    "|  FREE delivery on P300+ orders. Valid on 11/11 only.            |\n"
    "+==================================================================+\n";

const char* btsResponse = 
    "+==================================================================+\n"
    "|  BACK TO SCHOOL SALE! May 15 - June 30                          |\n"
    "|  20% OFF on notebooks, pens, art supplies.                      |\n"
    "|  15% OFF on school uniforms and bags. FREE lunch box for P1000. |\n"
    "+==================================================================+\n";

const char* easterSaleResponse = 
    "+==================================================================+\n"
    "|  EASTER SALE! 1 week before Easter Sunday                       |\n"
    "|  20% OFF on chocolates and candies. 10% OFF on party supplies.  |\n"
    "|  Easter basket bundles starting at P150. Happy Easter!          |\n"
    "+==================================================================+\n";

const char* eidResponse = 
    "+==================================================================+\n"
    "|  EID'L FITR MUBARAK! End of Ramadan celebration                 |\n"
    "|  20% OFF on halal-certified products. 15% OFF on dates.         |\n"
    "|  Store hours: 7:00 AM - 5:00 PM on Eid day.                     |\n"
    "+==================================================================+\n";

const char* eidAdhaResponse = 
    "+==================================================================+\n"
    "|  EID'L ADHA MUBARAK! Feast of Sacrifice                          |\n"
    "|  15% OFF on halal-certified meat products.                      |\n"
    "|  Store hours: 8:00 AM - 3:00 PM. May your sacrifices be accepted.|\n"
    "+==================================================================+\n";

const char* twelveResponse = 
    "+==================================================================+\n"
    "|  12.12 YEAR-END MEGA SALE! December 12 only                     |\n"
    "|  12% OFF storewide. Buy 1 Get 1 on gift items.                  |\n"
    "|  FREE gift wrapping. FREE delivery nationwide.                  |\n"
    "+==================================================================+\n";

const char* paydayResponse = 
    "+==================================================================+\n"
    "|  PAYDAY SALE! Every 15th and 30th of the month                  |\n"
    "|  10% OFF on all non-food items. Triple loyalty points.          |\n"
    "|  Buy 1 Take 1 on selected snacks. You deserve it!              |\n"
    "+==================================================================+\n";

const char* cnyResponse = 
    "+==================================================================+\n"
    "|  KUNG HEI FAT CHOY! Chinese New Year Sale                        |\n"
    "|  18% OFF on lucky items. 20% OFF on tikoy and delicacies.       |\n"
    "|  FREE red envelope with every purchase. Valid 1 week before CNY.|\n"
    "+==================================================================+\n";

const char* halloweenSaleResponse = 
    "+==================================================================+\n"
    "|  HALLOWEEN SPOOKTACULAR SALE! October 25-31                     |\n"
    "|  25% OFF on candies and chocolates. 20% OFF on costumes.        |\n"
    "|  Buy 1 Get 1 on party supplies. Don't be scared of prices!     |\n"
    "+==================================================================+\n";

const char* blackFriResponse = 
    "+==================================================================+\n"
    "|  BLACK FRIDAY + CYBER MONDAY! Nov 29 & Dec 2                    |\n"
    "|  30% OFF on electronics. 25% OFF on clothing. 20% OFF storewide.|\n"
    "|  Doorbuster deals 6-10 AM: Extra 40% off. FREE shipping.        |\n"
    "+==================================================================+\n";

const char* midyearResponse = 
    "+==================================================================+\n"
    "|  MID-YEAR SUMMER SALE! June 1 - July 15                         |\n"
    "|  25% OFF on sunglasses, swimwear, fans. 20% OFF on ice cream.   |\n"
    "|  Buy 1 Take 1 on summer snacks. Stay cool and save big!        |\n"
    "+==================================================================+\n";

// ==================== HOLIDAY ====================
const char* xmasResponse = 
    "+============================================================+\n"
    "|  MERRY CHRISTMAS from PILIKart!                           |\n"
    "|  Dec 24: 8AM-6PM  |  Dec 25: CLOSED                       |\n"
    "|  Dec 31: 8AM-6PM  |  Jan 1: CLOSED                        |\n"
    "|  Happy holidays! Thank you for your support!              |\n"
    "+============================================================+\n";

const char* nyResponse = 
    "+============================================================+\n"
    "|  HAPPY NEW YEAR from PILIKart!                            |\n"
    "|  Jan 1: CLOSED                                            |\n"
    "|  Resuming Jan 2. Wishing you health and happiness!        |\n"
    "+============================================================+\n";

const char* vdayResponse = 
    "+============================================================+\n"
    "|  HAPPY VALENTINE'S DAY!                                   |\n"
    "|  Buy 1 Get 1 on chocolates (Aisle 6)                      |\n"
    "|  10% off on flowers and gifts                             |\n"
    "|  Show some love to your special someone!                  |\n"
    "+============================================================+\n";

const char* holyWeekResponse = 
    "+============================================================+\n"
    "|  HOLY WEEK SCHEDULE                                       |\n"
    "|  Maundy Thu: 8AM-3PM  |  Good Fri: 9AM-5PM                |\n"
    "|  Black Sat: 9AM-7PM   |  Easter Sun: 9AM-7PM              |\n"
    "|  Have a blessed Holy Week!                                |\n"
    "+============================================================+\n";

const char* undasResponse = 
    "+============================================================+\n"
    "|  UNDAS SCHEDULE                                           |\n"
    "|  Nov 1 (All Saints): 8AM-5PM                              |\n"
    "|  Nov 2 (All Souls): 8AM-7PM                               |\n"
    "|  We remember and honor our departed loved ones            |\n"
    "+============================================================+\n";

const char* indepResponse = 
    "+============================================================+\n"
    "|  MALIGAYANG ARAW NG KALAYAAN!                             |\n"
    "|  10% off on all local products                            |\n"
    "|  Support local farmers and artisans                       |\n"
    "|  Mabuhay  Pilipinas!                                      |\n"
    "+============================================================+\n";

const char* heroesResponse = 
    "+============================================================+\n"
    "|  NATIONAL HEROES DAY                                      |\n"
    "|  Store hours: 9AM - 7PM                                   |\n"
    "|  Remembering the sacrifices of our Filipino heroes        |\n"
    "|  \"Ang hindi marunong lumingon sa pinanggalingan...\"     |\n"
    "+============================================================+\n";

const char* mothersResponse = 
    "+============================================================+\n"
    "|  HAPPY MOTHER'S DAY!                                      |\n"
    "|  15% off on home and kitchen items                        |\n"
    "|  FREE flower with every P500 purchase                     |\n"
    "|  You deserve the best, Mom!                               |\n"
    "+============================================================+\n";

const char* fathersResponse = 
    "+============================================================+\n"
    "|  HAPPY FATHER'S DAY!                                      |\n"
    "|  15% off on grilling and barbecue items                   |\n"
    "|  Buy 1 Take 1 on selected beers                           |\n"
    "|  FREE tool kit with P500 purchase                         |\n"
    "|  You're our hero, Dad!                                    |\n"
    "+============================================================+\n";

const char* customerResponse = 
    "+============================================================+\n"
    "|  CUSTOMER APPRECIATION DAY!                               |\n"
    "|  Every 15th of the month                                  |\n"
    "|  Triple loyalty points | FREE pandesal (first 50)         |\n"
    "|  Raffle entry for every P300 purchase                     |\n"
    "|  Thank you for choosing PILIKart!                         |\n"
    "+============================================================+\n";

const char* R_HABI = 
    "\n+==================================================================+\n"
    "|  HABI - Fashion Store                                            |\n"
    "+==================================================================+\n"
    "|  We offer stylish clothing for every occasion!                   |\n"
    "|  Try: bikini, shirt, pants, jeans, hoodie, skirt                 |\n"
    "|  Type 'display clothes' to see all items.                        |\n"
    "+==================================================================+\n";

const char* R_APOLLO = 
    "\n+==================================================================+\n"
    "|  APOLLO - Tech & Gadgets Store                                   |\n"
    "+==================================================================+\n"
    "|  Your one-stop shop for electronics and gadgets!                 |\n"
    "|  Try: usb, mouse, keyboard, headset, speaker                     |\n"
    "|  Type 'display tech' to see all items.                           |\n"
    "+==================================================================+\n";

const char* R_NIPA = 
    "\n+==================================================================+\n"
    "|  NIPA - Home & Furniture Store                                   |\n"
    "+==================================================================+\n"
    "|  Quality furniture for your dream home!                          |\n"
    "|  Try: bed, couch, table, cabinet, refrigerator                   |\n"
    "|  Type 'display furniture' to see all items.                      |\n"
    "+==================================================================+\n";

const char* R_PASO = 
    "\n+==================================================================+\n"
    "|  PASO - Grocery & Food Essentials                                |\n"
    "+==================================================================+\n"
    "|  Your daily food needs, fresh and affordable!                    |\n"
    "|  Try: water, bread, eggs, sardines, noodles, tocino              |\n"
    "|  Type 'display grocery' to see all items.                        |\n"
    "+==================================================================+\n";

// ==================== INIT KNOWLEDGE BASE ====================

void initKnowledgeBase() {
    int idx = 0;
    
    // SECTION 1: STORE INFO_____________________________________________________________
    const char* menuKW[] = {"menu", "help", "options", "commands"};
    addFAQ(knowledgeBase[idx], menuKW, 4, NULL, 0, menu);
    idx++;
    
    const char* hoursKW[] = {"hour", "hours", "open", "close", "schedule", "operating", "timing"};
    addFAQ(knowledgeBase[idx], hoursKW, 7, NULL, 0, hours);
    idx++;
    
    const char* locKW[] = {"location", "address", "where"};
    const char* locPH[] = {"where are you", "where is the store", "store located", "how to get there"};
    addFAQ(knowledgeBase[idx], locKW, 3, locPH, 4, loc);
    idx++;
    
    const char* contactKW[] = {"contact", "phone", "call", "email", "facebook", "messenger", "hotline"};
    addFAQ(knowledgeBase[idx], contactKW, 7, NULL, 0, contact);
    idx++;
    
    const char* parkKW[] = {"parking", "park", "parking slots"};
    addFAQ(knowledgeBase[idx], parkKW, 3, NULL, 0, parking);
    idx++;

    // SECTION 2: PRODUCTS & SHOPPING _____________________________________________________________
    const char* prodKW[] = {"aisle", "locate", "section", "milk", "bread", "meat", "rice", "juice", "eggs", "vegetables", "fruits"};
    const char* prodPH[] = {"where is", "find the", "product location"};
    addFAQ(knowledgeBase[idx], prodKW, 11, prodPH, 3, prodguide);
    idx++;
    
    const char* freshKW[] = {"fresh", "pandesal", "organic", "delivered", "baked"};
    const char* freshPH[] = {"free range", "freshly baked"};
    addFAQ(knowledgeBase[idx], freshKW, 5, freshPH, 2, fresh);
    idx++;
    
    const char* qualityKW[] = {"quality", "guarantee", "freshness", "satisfied", "return"};
    addFAQ(knowledgeBase[idx], qualityKW, 5, NULL, 0, quality);
    idx++;
    
    // SECTION 3: POLICIES & SERVICES_____________________________________________________________
    const char* pricePH[] = {"price match", "match price", "lower price", "competitor price", "cheaper elsewhere"};
    addFAQ(knowledgeBase[idx], NULL, 0, pricePH, 5, priceM);
    idx++;
    
    const char* specialKW[] = {"order", "request", "preorder"};
    const char* specialPH[] = {"special order", "out of stock", "not in stock", "bulk order"};
    addFAQ(knowledgeBase[idx], specialKW, 3, specialPH, 4, special);
    idx++;
    
    const char* loyaltyKW[] = {"loyalty", "rewards", "points", "member", "membership"};
    const char* loyaltyPH[] = {"loyalty card", "rewards card", "points balance"};
    addFAQ(knowledgeBase[idx], loyaltyKW, 5, loyaltyPH, 3, loyalty);
    idx++;
    
    const char* paymentKW[] = {"payment", "cash", "gcash", "maya", "credit", "debit", "card", "visa", "mastercard", "installment", "cod"};
    addFAQ(knowledgeBase[idx], paymentKW, 11, NULL, 0, payment);
    idx++;
    
    const char* deliveryKW[] = {"delivery", "deliver", "shipping", "deliveries"};
    addFAQ(knowledgeBase[idx], deliveryKW, 4, NULL, 0, delivery);
    idx++;
    
    const char* returnKW[] = {"return", "refund", "exchange", "spoiled", "damaged", "defective"};
    addFAQ(knowledgeBase[idx], returnKW, 6, NULL, 0, returns);
    idx++;
    
    const char* scanPH[] = {"price scan", "wrong price", "scan error", "shelf price", "price discrepancy"};
    addFAQ(knowledgeBase[idx], NULL, 0, scanPH, 5, scan);
    idx++;
    
    const char* seniorKW[] = {"senior", "pwd", "discount", "disabled", "senior citizen"};
    const char* seniorPH[] = {"senior card", "pwd card", "senior discount"};
    addFAQ(knowledgeBase[idx], seniorKW, 5, seniorPH, 3, senior);
    idx++;

    // SECTION 4: GREETINGS & THANKS_____________________________________________________________
    const char* greetKW[] = {"hello", "hi", "hey", "kamusta"};
    const char* greetPH[] = {"good morning", "good afternoon", "good evening", "how are you"};
    addFAQ(knowledgeBase[idx], greetKW, 4, greetPH, 4, greet);
    idx++;
    
    const char* thanksKW[] = {"thank", "thanks", "salamat", "ty"};
    addFAQ(knowledgeBase[idx], thanksKW, 4, NULL, 0, thanks);
    idx++;
    
    // SECTION 5: OTHER SERVICES_____________________________________________________________
    const char* holidayKW[] = {"holiday", "christmas", "new year", "easter", "halloween"};
    const char* holidayPH[] = {"holiday schedule", "special hours", "holiday hours"};
    addFAQ(knowledgeBase[idx], holidayKW, 5, holidayPH, 3,
    "\n+===========================================================+\n"
    "|                 PILIKart - HOLIDAY CALENDAR                |\n"
    "+============================================================+\n"
    "|                                                            |\n"
    "|  NATIONAL HOLIDAYS:                                        |\n"
    "|  Jan 1 (CLOSED) | Apr 9 | May 1 | Jun 12 (10% off local)   |\n"
    "|  Aug 21 | Aug 26 | Nov 30 | Dec 25 (CLOSED) | Dec 30       |\n"
    "|  Dec 31 (8AM-6PM)                                          |\n"
    "|                                                            |\n"
    "|  RELIGIOUS & CULTURAL:                                     |\n"
    "|  Holy Week (9AM-5PM) | Easter (9AM-7PM) | Eid (7AM-5PM)    |\n"
    "|  Nov 1 (8AM-5PM) | Nov 2 (8AM-7PM) | Dec 24 (8AM-6PM)      |\n"
    "|  Chinese NY (10% off) | Valentine's (B1G1 chocolates)      |\n"
    "|  Mother's Day (15% off paso) | Father's Day (15% off nipa) |\n"
    "|                                                            |\n"
    "|  SPECIAL SALES:                                            |\n"
    "|  May 3 (20% off) | Nov 11 (11% off) | Dec 12 (12% off)     |\n"
    "|  Black Friday (30% off electronics) | Payday (10% off)     |\n"
    "|  Back to School (20% off supplies)                         |\n"
    "|                                                            |\n"
    "|  Type holiday name for details (e.g., 'merry xmas')        |\n"
    "+============================================================+\n");
    idx++;
    
    const char* wifiKW[] = {"wifi", "internet", "connection", "hotspot"};
    const char* wifiPH[] = {"free wifi", "wifi password", "internet connection"};
    addFAQ(knowledgeBase[idx], wifiKW, 4, wifiPH, 3, wifi);
    idx++;
    
    const char* crKW[] = {"cr", "restroom", "bathroom", "toilet", "comfort room"};
    const char* crPH[] = {"where is the cr", "where is the restroom", "comfort room location"};
    addFAQ(knowledgeBase[idx], crKW, 5, crPH, 3, cr);
    idx++;
    
    const char* studentKW[] = {"student", "school", "college"};
    const char* studentPH[] = {"student discount", "school id"};
    addFAQ(knowledgeBase[idx], studentKW, 3, studentPH, 2, student);
    idx++;
    
    const char* bdayKW[] = {"birthday", "bday"};
    const char* bdayPH[] = {"birthday promo", "birthday month"};
    addFAQ(knowledgeBase[idx], bdayKW, 2, bdayPH, 2,
           "\n+==================================================================+\n"
           "|                       BIRTHDAY PROMO                               |\n"
           "+==================================================================+\n"
           "|  Double loyalty points during your birthday month!                 |\n"
           "|  FREE small cake when you spend 2000+php on your actual birthday!    |\n"
           "|  Just show any valid ID with your birthdate.                       |\n"
           "+==================================================================+\n");
    idx++;
    
    const char* bulkKW[] = {"bulk", "wholesale", "business"};
    const char* bulkPH[] = {"bulk order", "bulk purchase", "wholesale price"};
    addFAQ(knowledgeBase[idx], bulkKW, 3, bulkPH, 3,
           "\n+==================================================================+\n"
           "|                          BULK ORDERS                               |\n"
           "+====================================================================+\n"
           "|  YES! We accept bulk orders for businesses and events!             |\n"
           "|  Minimum order: 50+ units of same item                             |\n"
           "|  Processing time: 5-7 business days                                |\n"
           "|  Special pricing available! Call (049) 123-4567 to inquire.        |\n"
           "+==================================================================+\n");
    idx++;

    const char* capacityKW[] = {"capacity", "crowded", "puno"};
    const char* capacityPH[] = {"store capacity", "is it crowded", "many people"};
    addFAQ(knowledgeBase[idx], capacityKW, 3, capacityPH, 3,
           "\n+==================================================================+\n"
           "|                       STORE CAPACITY                              |\n"
           "+==================================================================+\n"
           "|  Maximum capacity: 200 customers                                  |\n"
           "|  Least crowded times: 9:00 AM - 11:00 AM and 2:00 PM - 4:00 PM    |\n"
           "|  Busiest times: 5:00 PM - 7:00 PM (after work hours)              |\n"
           "+==================================================================+\n");
    idx++;
    
    const char* jobKW[] = {"job", "work", "apply", "hiring", "employment"};
    const char* jobPH[] = {"job application", "apply for work", "job hiring"};
    addFAQ(knowledgeBase[idx], jobKW, 5, jobPH, 3,
           "\n+==================================================================+\n"
           "|                      JOB APPLICATION                               |\n"
           "+==================================================================+\n"
           "|  We're always looking for talented individuals!                    |\n"
           "|  Submit your resume to: hr@pilikart.com                            |\n"
           "|  Or visit our Customer Service counter for application forms.     |\n"
           "|  Current openings: Cashiers, Stock Clerks, Delivery Riders         |\n"
           "+==================================================================+\n");
    idx++;
    
    // SECTION 6: MEMES BA _____________________________________________________________
    
    const char* screamKW[] = {"aaaa", "aaa", "ahhh"};
    const char* screamPH[] = {"aaaaaaaaaaaaaaa"};
    addFAQ(knowledgeBase[idx], screamKW, 3, screamPH, 1, AAAA);
    idx++;
    
    const char* sixtySevenKW[] = {"67"};
    addFAQ(knowledgeBase[idx], sixtySevenKW, 1, NULL, 0, sixseven);
    idx++;
    
    const char* oneTwoThreeKW[] = {"123", "45"};
    const char* oneTwoThreePH[] = {"123, 45", "12345"};
    addFAQ(knowledgeBase[idx], oneTwoThreeKW, 2, oneTwoThreePH, 2, EASTER_12345);
    idx++;
    
    const char* idkKW[] = {"idk", "dont know"};
    const char* idkPH[] = {"idk what to ask", "i dont know what to ask"};
    addFAQ(knowledgeBase[idx], idkKW, 2, idkPH, 2, idk);
    idx++;
    
    const char* lifeKW[] = {"life", "meaning"};
    const char* lifePH[] = {"meaning of life"};
    addFAQ(knowledgeBase[idx], lifeKW, 2, lifePH, 1, MOLife);
    idx++;
    
    const char* ayawKW[] = {"ayaw"};
    const char* ayawPH[] = {"ayaw ko na"};
    addFAQ(knowledgeBase[idx], ayawKW, 1, ayawPH, 1, ayaw);
    idx++;
    
    const char* sanaKW[] = {"sana"};
    const char* sanaPH[] = {"sana all"};
    addFAQ(knowledgeBase[idx], sanaKW, 1, sanaPH, 1, sana);
    idx++;
    
    const char* skibidiKW[] = {"skibidi"};
    const char* skibidiPH[] = {"skibidi"};
        addFAQ(knowledgeBase[idx], skibidiKW, 1, skibidiPH, 1, skibidi);
    idx++;
    
    const char* rizzKW[] = {"rizz"};
    addFAQ(knowledgeBase[idx], rizzKW, 1, NULL, 0, rizz);
    idx++;
    
    const char* gyattKW[] = {"gyatt"};
    addFAQ(knowledgeBase[idx], gyattKW, 1, NULL, 0, gyatt);
    idx++;
    
    const char* fanumKW[] = {"fanum"};
    const char* fanumPH[] = {"fanum tax"};
    addFAQ(knowledgeBase[idx], fanumKW, 1, fanumPH, 1, fanum);
    idx++;
    
    const char* sigmaKW[] = {"sigma"};
    addFAQ(knowledgeBase[idx], sigmaKW, 1, NULL, 0, sigma);
    idx++;
    
    const char* alphaKW[] = {"alpha"};
    addFAQ(knowledgeBase[idx], alphaKW, 1, NULL, 0, alpha);
    idx++;
    
    const char* nocapKW[] = {"nocap", "cap"};
    const char* nocapPH[] = {"no cap"};
    addFAQ(knowledgeBase[idx], nocapKW, 2, nocapPH, 1, nocap);
    idx++;
    
    const char* betKW[] = {"bet"};
    addFAQ(knowledgeBase[idx], betKW, 1, NULL, 0, bet);
    idx++;
    
    const char* susKW[] = {"sus", "amogus", "mogus", "amongus"};
    addFAQ(knowledgeBase[idx], susKW, 4, NULL, 0, sus);
    idx++;
    
    const char* yeetKW[] = {"yeet"};
    addFAQ(knowledgeBase[idx], yeetKW, 1, NULL, 0, yeet);
    idx++;
    
    const char* frKW[] = {"fr"};
    const char* frPH[] = {"fr fr"};
    addFAQ(knowledgeBase[idx], frKW, 1, frPH, 1, fr);
    idx++;
    
    const char* ratioKW[] = {"ratio"};
    addFAQ(knowledgeBase[idx], ratioKW, 1, NULL, 0, ratio);
    idx++;
    
    const char* copeKW[] = {"cope", "seethe", "mald"};
    addFAQ(knowledgeBase[idx], copeKW, 3, NULL, 0, cope);
    idx++;
    
    const char* basedKW[] = {"based"};
    addFAQ(knowledgeBase[idx], basedKW, 1, NULL, 0, based);
    idx++;
    
    const char* cringeKW[] = {"cringe"};
    addFAQ(knowledgeBase[idx], cringeKW, 1, NULL, 0, cringe);
    idx++;
    
    const char* sheeshKW[] = {"sheesh"};
    addFAQ(knowledgeBase[idx], sheeshKW, 1, NULL, 0, sheesh);
    idx++;
    
    const char* bruhKW[] = {"bruh"};
    addFAQ(knowledgeBase[idx], bruhKW, 1, NULL, 0, bruh);
    idx++;
    
    const char* midKW[] = {"mid"};
    addFAQ(knowledgeBase[idx], midKW, 1, NULL, 0, mid);
    idx++;
    
    const char* bussinKW[] = {"bussin"};
    addFAQ(knowledgeBase[idx], bussinKW, 1, NULL, 0, bussin);
    idx++;
    
    const char* slayKW[] = {"slay", "periodt"};
    addFAQ(knowledgeBase[idx], slayKW, 2, NULL, 0, slay);
    idx++;
    
    const char* managerKW[] = {"manager"};
    const char* managerPH[] = {"give me your manager", "i want to speak to manager", "call the manager"};
    addFAQ(knowledgeBase[idx], managerKW, 1, managerPH, 3, manager);
    idx++;
    
    const char* maincharKW[] = {"main"};
    const char* maincharPH[] = {"main character"};
    addFAQ(knowledgeBase[idx], maincharKW, 1, maincharPH, 1, mainchar);
    idx++;
    
    const char* povKW[] = {"pov"};
    addFAQ(knowledgeBase[idx], povKW, 1, NULL, 0, pov);
    idx++;
    
    const char* npcKW[] = {"npc"};
    addFAQ(knowledgeBase[idx], npcKW, 1, NULL, 0, npc);
    idx++;
    
    const char* charotKW[] = {"charot", "charing"};
    addFAQ(knowledgeBase[idx], charotKW, 2, NULL, 0, charot);
    idx++;
    
    const char* luhKW[] = {"luh"};
    addFAQ(knowledgeBase[idx], luhKW, 1, NULL, 0, luh);
    idx++;
    
    const char* ediwowKW[] = {"edi"};
    const char* ediwowPH[] = {"edi wow"};
    addFAQ(knowledgeBase[idx], ediwowKW, 1, ediwowPH, 1, ediwow);
    idx++;
    
    const char* pakKW[] = {"pak"};
    addFAQ(knowledgeBase[idx], pakKW, 1, NULL, 0, pak);
    idx++;
    
    const char* chikaKW[] = {"chika"};
    addFAQ(knowledgeBase[idx], chikaKW, 1, NULL, 0, chika);
    idx++;
    
    const char* meltKW[] = {"init", "melt", "melting"};
    addFAQ(knowledgeBase[idx], meltKW, 3, NULL, 0, melt);
    idx++;
       
    const char* supKW[] = {"sup"};
    const char* supPH[] = {"what's up", "wassup"};
    addFAQ(knowledgeBase[idx], supKW, 1, supPH, 2, sup);
    idx++;
    
    const char* howKW[] = {"how"};
    const char* howPH[] = {"how are you", "kamusta ka"};
    addFAQ(knowledgeBase[idx], howKW, 1, howPH, 2, howru);
    idx++;
    
    const char* secretKW[] = {"secret"};
    const char* secretPH[] = {"secret menu", "hidden menu"};
    addFAQ(knowledgeBase[idx], secretKW, 1, secretPH, 2, sanasecret);
    idx++;
    
    const char* rickKW[] = {"rick"};
    const char* rickPH[] = {"rickroll", "never gonna"};
    addFAQ(knowledgeBase[idx], rickKW, 1, rickPH, 2, rickroll);
    idx++;
    
    const char* otwKW[] = {"otw"};
    const char* otwPH[] = {"on the way"};
    addFAQ(knowledgeBase[idx], otwKW, 1, otwPH, 1, otw);
    idx++;
    
    const char* lodiKW[] = {"lodi"};
    addFAQ(knowledgeBase[idx], lodiKW, 1, NULL, 0, lodi);
    idx++;
    
    const char* petmaluKW[] = {"petmalu"};
    addFAQ(knowledgeBase[idx], petmaluKW, 1, NULL, 0, petmalu);
    idx++;
    
    const char* konamiKW[] = {"kunomi", "konami", "cheat", "code"};
    const char* konamiPH[] = {"up up down down left right left right b a"};
    addFAQ(knowledgeBase[idx], konamiKW, 4, konamiPH, 1, kunomi);
    idx++;
    
    const char* gamemodeKW[] = {"gamemode"};
    const char* gamemodePH[] = {"gamemode creative"};
    addFAQ(knowledgeBase[idx], gamemodeKW, 1, gamemodePH, 1, gamemodeC);
    idx++;
    
    const char* killKW[] = {"kill"};
    const char* killPH[] = {"/kill"};
    addFAQ(knowledgeBase[idx], killKW, 1, killPH, 1, kill);
    idx++;
   
    // SECTION 7: PRICES/PRODUCTS _____________________________________________________________
    const char* milkKW[] = {"milk", "gatas"};
    const char* milkPH[] = {"how much is milk", "milk price"};
    addFAQ(knowledgeBase[idx], milkKW, 2, milkPH, 2, milk);
    idx++;
    
    const char* breadKW[] = {"bread", "pandesal"};
    const char* breadPH[] = {"how much is bread", "bread price"};
    addFAQ(knowledgeBase[idx], breadKW, 2, breadPH, 2, bread);
    idx++;
    
    const char* riceKW[] = {"rice", "kanin"};
    const char* ricePH[] = {"how much is rice", "rice price"};
    addFAQ(knowledgeBase[idx], riceKW, 2, ricePH, 2, rice);
    idx++;
    
    const char* eggsKW[] = {"eggs", "itlog"};
    const char* eggsPH[] = {"how much is eggs", "egg price"};
    addFAQ(knowledgeBase[idx], eggsKW, 2, eggsPH, 2, eggs);
    idx++;
    
    const char* chickenKW[] = {"chicken", "manok"};
    const char* chickenPH[] = {"how much is chicken", "chicken price"};
    addFAQ(knowledgeBase[idx], chickenKW, 2, chickenPH, 2, chicken);
    idx++;
    
    const char* porkKW[] = {"pork", "baboy"};
    const char* porkPH[] = {"how much is pork", "pork price"};
    addFAQ(knowledgeBase[idx], porkKW, 2, porkPH, 2, pork);
    idx++;
    
    const char* cokeKW[] = {"coke", "coca", "softdrinks"};
    const char* cokePH[] = {"how much is coke", "coke price"};
    addFAQ(knowledgeBase[idx], cokeKW, 3, cokePH, 2, coke);
    idx++;
    
    const char* coffeeKW[] = {"coffee", "kape", "nescafe"};
    const char* coffeePH[] = {"how much is coffee", "coffee price"};
    addFAQ(knowledgeBase[idx], coffeeKW, 3, coffeePH, 2, coffee);
    idx++;
    
    const char* cornedKW[] = {"corned"};
    const char* cornedPH[] = {"corned beef", "how much is corned beef"};
    addFAQ(knowledgeBase[idx], cornedKW, 1, cornedPH, 2, cornedBeef);
    idx++;
    
    const char* sardinesKW[] = {"sardinas", "sardines"};
    const char* sardinesPH[] = {"how much is sardines", "sardines price"};
    addFAQ(knowledgeBase[idx], sardinesKW, 2, sardinesPH, 2, sardines);
    idx++;
    
    // SECTION 8: SALES_____________________________________________________________
    const char* generalSaleKW[] = {"sale", "sales", "promo", "promotion"};
    const char* generalSalePH[] = {"do you have sales", "any sale", "promo ngayon", "may discount ba"};
    addFAQ(knowledgeBase[idx], generalSaleKW, 4, generalSalePH, 4, generalSaleResponse);
    idx++;
    
    const char* foundationKW[] = {"foundation day", "anniversary", "founding"};
    const char* foundationPH[] = {"may 3 sale", "foundation sale", "anniversary sale"};
    addFAQ(knowledgeBase[idx], foundationKW, 3, foundationPH, 3, foundationResponse);
    idx++;
    
    const char* elevenKW[] = {"11.11", "eleven eleven", "1111"};
    const char* elevenPH[] = {"11.11 sale", "double eleven sale"};
    addFAQ(knowledgeBase[idx], elevenKW, 3, elevenPH, 2, elevenResponse);
    idx++;
    
    const char* btsKW[] = {"back to school", "school supplies", "bts"};
    const char* btsPH[] = {"school sale", "school supply sale"};
    addFAQ(knowledgeBase[idx], btsKW, 3, btsPH, 2, btsResponse);
    idx++;
    
    const char* easterSaleKW[] = {"easter sale", "spring sale"};
    const char* easterSalePH[] = {"easter promo", "easter discount"};
    addFAQ(knowledgeBase[idx], easterSaleKW, 2, easterSalePH, 2, easterSaleResponse);
    idx++;
    
    const char* eidKW[] = {"eid", "eid al fitr", "ramadan"};
    const char* eidPH[] = {"eid'l fitr", "eid sale", "muslim holiday"};
    addFAQ(knowledgeBase[idx], eidKW, 3, eidPH, 3, eidResponse);
    idx++;
    
    const char* eidAdhaKW[] = {"eid al adha", "eid adha"};
    const char* eidAdhaPH[] = {"eid'l adha", "feast of sacrifice"};
    addFAQ(knowledgeBase[idx], eidAdhaKW, 2, eidAdhaPH, 2, eidAdhaResponse);
    idx++;
    
    const char* twelveKW[] = {"12.12", "twelve twelve", "1212"};
    const char* twelvePH[] = {"12.12 sale", "year end sale"};
    addFAQ(knowledgeBase[idx], twelveKW, 3, twelvePH, 2, twelveResponse);
    idx++;
    
    const char* paydayKW[] = {"payday", "salary", "sweldo"};
    const char* paydayPH[] = {"payday sale", "payday promo"};
    addFAQ(knowledgeBase[idx], paydayKW, 3, paydayPH, 2, paydayResponse);
    idx++;
    
    const char* cnyKW[] = {"chinese new year", "lunar new year", "cny"};
    const char* cnyPH[] = {"chinese new year sale", "lunar new year promo"};
    addFAQ(knowledgeBase[idx], cnyKW, 3, cnyPH, 2, cnyResponse);
    idx++;
    
    const char* halloweenSaleKW[] = {"halloween sale", "halloween promo"};
    const char* halloweenSalePH[] = {"halloween discount", "october 31"};
    addFAQ(knowledgeBase[idx], halloweenSaleKW, 2, halloweenSalePH, 2, halloweenSaleResponse);
    idx++;
    
    const char* blackFriKW[] = {"black friday", "cyber monday"};
    const char* blackFriPH[] = {"black friday sale", "cyber monday sale"};
    addFAQ(knowledgeBase[idx], blackFriKW, 2, blackFriPH, 2, blackFriResponse);
    idx++;
    
    const char* midyearKW[] = {"mid year sale", "summer sale"};
    const char* midyearPH[] = {"midyear sale", "june sale"};
    addFAQ(knowledgeBase[idx], midyearKW, 2, midyearPH, 2, midyearResponse);
    idx++;

    // SECTION 9: HOLIDAY PT2_____________________________________________________________
    const char* xmasKW[] = {"merry christmas", "happy christmas"};
    const char* xmasPH[] = {"merry christmas", "happy christmas", "xmas"};
    addFAQ(knowledgeBase[idx], NULL, 0, xmasPH, 3, xmasResponse);
    idx++;
    
    const char* nyKW[] = {"happy new year", "new year"};
    const char* nyPH[] = {"happy new year", "new year greeting"};
    addFAQ(knowledgeBase[idx], NULL, 0, nyPH, 2, nyResponse);
    idx++;
    
    const char* vdayKW[] = {"valentine", "valentines"};
    const char* vdayPH[] = {"happy valentine's day", "valentine's day"};
    addFAQ(knowledgeBase[idx], vdayKW, 2, vdayPH, 2, vdayResponse);
    idx++;
    
    const char* holyKW[] = {"holy week", "good friday", "easter"};
    const char* holyPH[] = {"holy week schedule", "easter sunday"};
    addFAQ(knowledgeBase[idx], holyKW, 3, holyPH, 2, holyWeekResponse);
    idx++;
    
    const char* undasKW[] = {"undas", "all saints", "all souls"};
    const char* undasPH[] = {"all saints day", "all souls day", "november 1", "november 2"};
    addFAQ(knowledgeBase[idx], undasKW, 3, undasPH, 4, undasResponse);
    idx++;
    
    const char* indepKW[] = {"independence day", "araw ng kalayaan"};
    addFAQ(knowledgeBase[idx], indepKW, 2, NULL, 0, indepResponse);
    idx++;
    
    const char* heroesKW[] = {"national heroes day", "heroes day"};
    addFAQ(knowledgeBase[idx], heroesKW, 2, NULL, 0, heroesResponse);
    idx++;
    
    const char* mothersKW[] = {"mothers day", "mother's day"};
    addFAQ(knowledgeBase[idx], mothersKW, 2, NULL, 0, mothersResponse);
    idx++;
    
    const char* fathersKW[] = {"fathers day", "father's day"};
    addFAQ(knowledgeBase[idx], fathersKW, 2, NULL, 0, fathersResponse);
    idx++;
    
    const char* customerKW[] = {"customer appreciation", "thank you customer"};
    addFAQ(knowledgeBase[idx], customerKW, 2, NULL, 0, customerResponse);
    idx++;
    
    // SECTION 10: DEPARTMENT STORES (H,A,N,P)_____________________________________________________________
    
    const char* habiKW[] = {"habi", "haba", "clothing", "fashion", "clothes", "apparel"};
    addFAQ(knowledgeBase[idx], habiKW, 6, NULL, 0, R_HABI);
    idx++;
    
    const char* apolloKW[] = {"apollo", "tech", "gadgets", "electronics", "computer"};
    addFAQ(knowledgeBase[idx], apolloKW, 5, NULL, 0, R_APOLLO);
    idx++;
    
    const char* nipaKW[] = {"nipa", "furniture", "home", "appliances"};
    addFAQ(knowledgeBase[idx], nipaKW, 4, NULL, 0, R_NIPA);
    idx++;
    
    const char* pasoKW[] = {"paso", "grocery", "groceries", "food", "essentials"};
    addFAQ(knowledgeBase[idx], pasoKW, 5, NULL, 0, R_PASO);
    idx++;

    knowledgeBaseSize = idx;
}
// + ============================================ MAIN FUNCTION ================================================ +
int main() {
    char name[max_name];
    char input[max_input];
    char lowerInput[max_input];
    initKnowledgeBase();
    
    //Title Banner
    //Na para bang game log in page yan sya
    cout << "\n";
    cout << "\n";
    cout << "+===============================================================================+\n";
    cout << "|                      ----- W E L C O M E    T O -----                         |\n";
    cout << "|                ##### ##### #      ##### #   #  ####  ####  #####              |\n";
    cout << "|                #   #   #   #        #   #  #  #    # #   #   #                |\n";
    cout << "|                #****   #   #        #   ###   #****# ####    #                |\n";
    cout << "|                #       #   #        #   #  #  #    # #   #   #                |\n";
    cout << "|                #     ##### ###### ##### #   # #    # #   #   #                |\n";
    cout << "+===============================================================================+\n";
    cout << "|                                                                               |\n";
    cout << "|                     + ================================= +                     |\n";
    cout << "|                   | Pili (Choose) | Ka (You) | Kart (Cart) |                  |\n";
    cout << "|                     + ================================= +                     |\n";
    cout << "|                                                                               |\n";  
    cout << "|                    >>> Choose to your heart's content <<<                     |\n";
    cout << "|                                                                               |\n";
    cout << "+===============================================================================+\n";
    cout << "\n";
    cout << "\n";
    // LORE DROP: I like adventure time and 'PB' may stand for PiliBot, but it can also be a play on 'Princess Bubblegum' ehehheeheh im so cool ba
    cout << "[PiliBot] Hi there! I'm PiliBot. What's your name? ";
    cin.getline(name, max_name);
    
    if (strlen(name) == 0) {
        strcpy(name, "Ka-PiliKArt");
    }
    // Remove achuchu sa mga names ba
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            name[i] = '\0';
            break;
        }
    }
    cout << "\n[PiliBot] Hi " << name << "! Welcome to PILIKart!\n";
    cout << "[PiliBot] Where you can choose to your heart's content.\n";
    cout << "[PiliBot] Type 'menu' to see what I can help with, or 'exit' to leave.\n\n";

    while (true) {
        cout << "[" << name << "] ";
        cin.getline(input, max_input);
        if (strlen(input) == 0) {
            continue;
        }
        strcpy(lowerInput, input);
        toLower(lowerInput);

        if (contains(lowerInput, "exit") || contains(lowerInput, "quit") || contains(lowerInput, "bye")) {
            cout << "\n[PiliBot] Thank you for visiting, " << name << "!\n";
            cout << "[PiliBot] Salamat po! Balik po kayo sa PILIKart!\n\n";
            cout << "\n";
    cout << "+===============================================================================+\n";
    cout << "|                      ----- THANK YOU FOR SHOPPING AT -----                    |\n";
    cout << "|                ##### ##### #      ##### #   #  ####  ####  #####              |\n";
    cout << "|                #   #   #   #        #   #  #  #    # #   #   #                |\n";
    cout << "|                #****   #   #        #   ###   #****# ####    #                |\n";
    cout << "|                #       #   #        #   #  #  #    # #   #   #                |\n";
    cout << "|                #     ##### ###### ##### #   # #    # #   #   #                |\n";
    cout << "+===============================================================================+\n";
            break;
        }  
        
        bool found = false;
    
        // CHECK FOR "DISPLAY" COMMANDS FIRST (4 depts "resolution") LOL debugg lng to sir
        if (contains(lowerInput, "display") || contains(lowerInput, "list all") || 
            contains(lowerInput, "list") || contains(lowerInput, "see all")) {
            
            if (contains(lowerInput,"clothes") || contains(lowerInput, "clothing") 
            || contains(lowerInput, "fashion") || contains(lowerInput, "habi")) {
                displayAllClothes();
                found = true;
            } else if (contains(lowerInput,"tech") || contains(lowerInput, "gadgets") 
            || contains(lowerInput, "electronics") || contains(lowerInput, "apollo")) {
                displayAllTech();
                found = true;
            } else if (contains(lowerInput,"furniture") || contains(lowerInput, "home") 
            || contains(lowerInput, "appliances") || contains(lowerInput, "nipa")) {
                displayAllFurniture();
                found = true;
            } else if (contains(lowerInput,"grocery") || contains(lowerInput, "food") 
            || contains(lowerInput, "groceries") || contains(lowerInput, "paso")) {
                displayAllGrocery();
                found = true;
            }
        }
        // CHECK FOR PRODUCT SEARCHES (same thing lng po, kasi nagkaka-conflict sa dept stores )
        if (!found) {
            // CLOTHING 
            if (contains(lowerInput, "bikini") || contains(lowerInput, "shirt") || 
                contains(lowerInput, "pants") || contains(lowerInput, "jeans") ||
                contains(lowerInput, "hoodie") || contains(lowerInput, "skirt") ||
                contains(lowerInput, "leggings") || contains(lowerInput, "tuxedo") ||
                contains(lowerInput, "crop") || contains(lowerInput, "jogging") ||
                contains(lowerInput, "maong") || contains(lowerInput, "cargo")) {
                searchClothing(lowerInput);
                found = true;
            }
            // TECH
            else if (contains(lowerInput, "usb") || contains(lowerInput, "mouse") || 
                     contains(lowerInput, "keyboard") || contains(lowerInput, "headset") ||
                     contains(lowerInput, "powerbank") || contains(lowerInput, "power bank") ||
                     contains(lowerInput, "smartwatch") || contains(lowerInput, "speaker") ||
                     contains(lowerInput, "webcam") || contains(lowerInput, "hard drive") ||
                     contains(lowerInput, "charger") || contains(lowerInput, "cable") ||
                     contains(lowerInput, "hdmi") || contains(lowerInput, "lamp") ||
                     contains(lowerInput, "type c") || contains(lowerInput, "flash drive")) {
                searchTech(lowerInput);
                found = true;
            }
            // FURNITURE 
            else if (contains(lowerInput, "bed") || contains(lowerInput, "couch") || 
                     contains(lowerInput, "sofa") || contains(lowerInput, "table") ||
                     contains(lowerInput, "refrigerator") || contains(lowerInput, "fridge") ||
                     contains(lowerInput, "vacuum") || contains(lowerInput, "cabinet") ||
                     contains(lowerInput, "aircon") || contains(lowerInput, "air conditioner") ||
                     contains(lowerInput, "comforter") || contains(lowerInput, "blanket") ||
                     contains(lowerInput, "pillow") || contains(lowerInput, "vanity")) {
                searchFurniture(lowerInput);
                found = true;
            }
            // GROCERY
            else if (contains(lowerInput, "water") || contains(lowerInput, "soda") || 
                     contains(lowerInput, "milk") || contains(lowerInput, "bread") ||
                     contains(lowerInput, "pancit") || contains(lowerInput, "canton") ||
                     contains(lowerInput, "noodles") || contains(lowerInput, "sardinas") ||
                     contains(lowerInput, "sardines") || contains(lowerInput, "keso") ||
                     contains(lowerInput, "eggs") || contains(lowerInput, "itlog") ||
                     contains(lowerInput, "cheese") || contains(lowerInput, "cheddar") ||
                     contains(lowerInput, "chips") || contains(lowerInput, "snacks") ||
                     contains(lowerInput, "flour") || contains(lowerInput, "sugar") ||
                     contains(lowerInput, "pasta") || contains(lowerInput, "tocino")) {
                searchGrocery(lowerInput);
                found = true;
            }
        }
        if (!found) {
            for (int i = 0; i < knowledgeBaseSize; i++) {
                if (matchesFAQ(lowerInput, knowledgeBase[i])) {
                    cout << knowledgeBase[i].response << "\n";
                    found = true;
                    break;
                }}}
        // Invalid input misij
        if (!found) {
            cout << "\n[PiliBot] Sorry, I didn't understand that.\n";
            cout << "[PiliBot] Type 'menu' to see what I can help with.\n\n";
        }
    }
    return 0;
} //eyy year of birth easter egg