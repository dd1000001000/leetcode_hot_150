class Solution {
public:
    string simplifyPath(string path) {
        stack<string> directories;
        string component;
        stringstream stream(path);
        while (getline(stream, component, '/')) {
            if (component.empty() || component == ".") {
                continue;
            }
            if (component == "..") {
                if (!directories.empty()) {
                    directories.pop();
                }
            } else {
                directories.push(component);
            }
        }

        vector<string> components;
        while (!directories.empty()) {
            components.push_back(directories.top());
            directories.pop();
        }
        reverse(components.begin(), components.end());

        string answer;
        for (const string& name : components) {
            answer += "/" + name;
        }
        return answer.empty() ? "/" : answer;
    }
};
