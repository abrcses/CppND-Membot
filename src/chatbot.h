#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;

    // data handles (owned)
    std::unique_ptr<ChatLogic> _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot(std::unique_ptr<ChatLogic> chatLogic);                     // constructor
    ChatBot(std::string filename); // constructor (filename is ignored in CLI)
    ~ChatBot();
    ChatBot(const ChatBot& other);
    ChatBot& operator=(const ChatBot& other);
    ChatBot(ChatBot&& other) noexcept;
    ChatBot& operator=(ChatBot&& other) noexcept;

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */