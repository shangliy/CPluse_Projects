#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
//{
//    std::cout << "ChatBot Move Assignment Operator" << std::endl;
//    _chatBot = chatbot;
//    _chatBot->SetCurrentNode(this);
//}

void GraphNode::MoveChatbotHere(ChatBot &&chatBot) {
    _chatBot = std::move(chatBot);
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(
            &_chatBot); // immediately update the _chatBot handle inside ChatLogic
    _chatBot.SetCurrentNode(this);
}



void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "ChatBot Move Constructor" << std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}