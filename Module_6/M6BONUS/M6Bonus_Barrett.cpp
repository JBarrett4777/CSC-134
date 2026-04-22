// M6bonus
// CSC 134
// Janiya Barrett
// 4/22/26

#include <iostream>  
#include <fstream>   
#include <cmath>  
using namespace std;

int main() {
    // 1. Define dimensions and file path
    const int width = 500;  
    const int height = 500;
    const int maxColor = 255; // Standard max color value 
    
    ofstream outFile("smiley.ppm"); 

    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    // 2. Write the PPM Header 
    // Line 1: Magic number 
    outFile << "P3" << endl;
    // Line 2: Width and Height 
    outFile << width << " " << height << endl;
    // Line 3: Maximum color value 
    outFile << maxColor << endl;

    // 3. Use nested loops to write RGB values for each pixel 
    for (int y = 0; y < height; y++) {       // Outer loop handles rows 
        for (int x = 0; x < width; x++) {   // Inner loop handles columns 
            
            // Define centers for geometry
            int centerX = width / 2;
            int centerY = height / 2;

            // Math: Distance Formula sqrt((x-cx)^2 + (y-cy)^2) 
            double distToCenter = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

            // Eye positions relative to center
            double distToLeftEye = sqrt(pow(x - (centerX - 70), 2) + pow(y - (centerY - 60), 2));
            double distToRightEye = sqrt(pow(x - (centerX + 70), 2) + pow(y - (centerY - 60), 2));

            bool isCyan = false;

            // DRAW HEAD: A ring with a radius of approximately 180 pixels
            if (distToCenter < 185 && distToCenter > 175) {
                isCyan = true;
            }
            // DRAW EYES: Small circles with a radius of 20 pixels
            else if (distToLeftEye < 20 || distToRightEye < 20) {
                isCyan = true;
            }
            // DRAW MOUTH: Semi-circle arc [cite: 63]
            // Checks if pixel is on the mouth radius and in the lower half of the face
            else if (distToCenter < 110 && distToCenter > 100 && y > centerY + 20) {
                isCyan = true;
            }

            // Write RGB values: Cyan (0, 255, 255) or Black (0, 0, 0)
            if (isCyan) {
                outFile << "0 255 255 ";
            } else {
                outFile << "0 0 0 ";
            }
        }
        outFile << "\n"; // Newline after each row to keep it readable 
    }

    outFile.close(); // Always close the file to prevent truncation 
    cout << "Image 'smiley.ppm' generated successfully." << endl;

    return 0;
}