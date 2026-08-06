#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"

// forward declarations
class GraphEdge;

class GraphNode
{
private:

    //// TODO
    
    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes
    std::unique_ptr<ChatBot> _chatBot;

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
   
    //// End of TODO


    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }
    std::unique_ptr<ChatBot>& GetChatBot() {return _chatBot; }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(GraphEdge *edge); // TODO

    void moveChatbotHere(ChatBot&& chatBot); // TODO

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
