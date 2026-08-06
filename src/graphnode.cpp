#include "chatbot.h"
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    // leave as-is
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge* edge)
{
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge)); // TODO
}


void GraphNode::moveChatbotHere(ChatBot&& chatbot) 
{
    _chatBot = std::make_unique<ChatBot>(std::move(chatbot));
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->moveChatbotHere(std::move(*_chatBot)); // TODO
}


GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    return _childEdges[index].get(); // TODO
}