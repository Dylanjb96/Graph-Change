#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>

// Include the nlohmann JSON library
// You can get it from: https://github.com/nlohmann/json/releases
#include "json.hpp"

using json = nlohmann::json;

// Generate a random time between start and end (in seconds since epoch)
std::time_t random_time(std::time_t start, std::time_t end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::time_t> dist(start, end);
    return dist(gen);
}

// Format time as ISO 8601 (e.g., 2024-07-20T15:30:00)
std::string format_iso8601(std::time_t time) {
    std::tm* tm = std::localtime(&time);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", tm);
    return std::string(buffer);
}

int main() {
    // Number of random commits
    const int numCommits = 500;
    const std::string filePath = "data.json"; //Date commits

    // Calculate time range (1 year ago to now)
    std::time_t now = std::time(nullptr);
    std::time_t oneYearAgo = now - (365 * 24 * 60 * 60);

    for (int i = 0; i < numCommits; ++i) {
        // Generate random date
        std::time_t randTime = random_time(oneYearAgo, now);
        std::string dateStr = format_iso8601(randTime);
        std::cout << "📅 Commit Date: " << dateStr << std::endl;

        // Create JSON data
        json j;
        j["date"] = dateStr;

        // Write to data.json
        std::ofstream file(filePath);
        file << j.dump(4); // Pretty print
        file.close();

        // Git commit
        std::string addCmd = "git add " + filePath;
        std::string commitCmd = "git commit -m \"" + dateStr + "\" --date=\"" + dateStr + "\"";

        std::system(addCmd.c_str());
        std::system(commitCmd.c_str());
    }

    // Final push
    std::system("git push");

    return 0;
}