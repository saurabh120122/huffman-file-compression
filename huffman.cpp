#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(NULL), right(NULL) {}
};

// Min-heap comparison
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build frequency map
unordered_map<char, int> buildFrequency(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    return freq;
}

// Traverse tree and store codes
void buildCodes(Node* root, string str, unordered_map<char, string>& huffCode) {
    if (!root) return;
    if (!root->left && !root->right)
        huffCode[root->ch] = str;
    buildCodes(root->left, str + "0", huffCode);
    buildCodes(root->right, str + "1", huffCode);
}

// Encode input text
string encode(const string& text, unordered_map<char, string>& huffCode) {
    string encoded = "";
    for (char ch : text)
        encoded += huffCode[ch];
    return encoded;
}

// Decode encoded string
string decode(Node* root, const string& encoded) {
    string result = "";
    Node* curr = root;
    for (char bit : encoded) {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right) {
            result += curr->ch;
            curr = root;
        }
    }
    return result;
}

int main() {
    string text = "abacabad";

    // Step 1: Build frequency map
    unordered_map<char, int> freq = buildFrequency(text);

    // Step 2: Build priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& entry : freq)
        pq.push(new Node(entry.first, entry.second));

    // Step 3: Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();

    // Step 4: Build Huffman codes
    unordered_map<char, string> huffCode;
    buildCodes(root, "", huffCode);

    cout << "Character codes:\n";
    for (auto& pair : huffCode)
        cout << pair.first << ": " << pair.second << "\n";

    // Step 5: Encode
    string encoded = encode(text, huffCode);
    cout << "\nEncoded: " << encoded << "\n";

    // Step 6: Decode
    string decoded = decode(root, encoded);
    cout << "Decoded: " << decoded << "\n";

    return 0;
}
