/**
* Copyright (c) 2018 Zilliqa
* This source code is being disclosed to you solely for the purpose of your participation in
* testing Zilliqa. You may view, compile and run the code for that purpose and pursuant to
* the protocols and algorithms that are programmed into, and intended by, the code. You may
* not do anything else with the code without express permission from Zilliqa Research Pte. Ltd.,
* including modifying or publishing the code (or any part of it), and developing or forming
* another public or private blockchain network. This source code is provided ‘as is’ and no
* warranties are given as to title or non-infringement, merchantability or fitness for purpose
* and, to the extent permitted by law, all liability for your use of the code is disclaimed.
* Some programs in this code are governed by the GNU General Public License v3.0 (available at
* https://www.gnu.org/licenses/gpl-3.0.en.html) (‘GPLv3’). The programs that are governed by
* GPLv3.0 are those programs that are located in the folders src/depends and tests/depends
* and which include a reference to GPLv3 in their program files.
**/
#include "Constants.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

struct PTree
{
    static ptree& GetInstance()
    {
        static ptree pt;
        read_xml("constants.xml", pt);

        return pt;
    }
    PTree() = delete;
    ~PTree() = delete;
};

unsigned int ReadFromConstantsFile(std::string propertyName)
{
    auto pt = PTree::GetInstance();
    return pt.get<unsigned int>("node.constants." + propertyName);
}

std::string ReadHexStringFromConnstansFile(std::string propertyName)
{
    auto pt = PTree::GetInstance();
    return pt.get<std::string>("node.constants." + propertyName);
}

const unsigned int DS_MULTICAST_CLUSTER_SIZE{
    ReadFromConstantsFile("DS_MULTICAST_CLUSTER_SIZE")};
const unsigned int COMM_SIZE{ReadFromConstantsFile("COMM_SIZE")};
const unsigned int MAX_POW1_WINNERS{ReadFromConstantsFile("MAX_POW1_WINNERS")};
const unsigned int POW1_WINDOW_IN_SECONDS{
    ReadFromConstantsFile("POW1_WINDOW_IN_SECONDS")};
const unsigned int POW1_BACKUP_WINDOW_IN_SECONDS{
    ReadFromConstantsFile("POW1_BACKUP_WINDOW_IN_SECONDS")};
const unsigned int LEADER_SHARDING_PREPARATION_IN_SECONDS{
    ReadFromConstantsFile("LEADER_SHARDING_PREPARATION_IN_SECONDS")};
const unsigned int LEADER_POW2_WINDOW_IN_SECONDS{
    ReadFromConstantsFile("LEADER_POW2_WINDOW_IN_SECONDS")};
const unsigned int BACKUP_POW2_WINDOW_IN_SECONDS{
    ReadFromConstantsFile("BACKUP_POW2_WINDOW_IN_SECONDS")};
const unsigned int NEW_NODE_SYNC_INTERVAL{
    ReadFromConstantsFile("NEW_NODE_SYNC_INTERVAL")};
const unsigned int POW_SUB_BUFFER_TIME{
    ReadFromConstantsFile("POW_SUB_BUFFER_TIME")}; //milliseconds
const unsigned int POW1_DIFFICULTY{ReadFromConstantsFile("POW1_DIFFICULTY")};
const unsigned int POW2_DIFFICULTY{ReadFromConstantsFile("POW2_DIFFICULTY")};
const unsigned int MICROBLOCK_TIMEOUT{
    ReadFromConstantsFile("MICROBLOCK_TIMEOUT")};
const unsigned int VIEWCHANGE_TIME{ReadFromConstantsFile("VIEWCHANGE_TIME")};
const unsigned int NUM_FINAL_BLOCK_PER_POW{
    ReadFromConstantsFile("NUM_FINAL_BLOCK_PER_POW")};
const unsigned int NUM_DS_KEEP_TX_BODY{
    ReadFromConstantsFile("NUM_DS_KEEP_TX_BODY")};
const uint32_t MAXMESSAGE{ReadFromConstantsFile("MAXMESSAGE")};
const unsigned int MAXSUBMITTXNPERNODE{
    ReadFromConstantsFile("MAXSUBMITTXNPERNODE")};
const unsigned int TX_SHARING_CLUSTER_SIZE{
    ReadFromConstantsFile("TX_SHARING_CLUSTER_SIZE")};
const std::string GENESIS_PRIVATE_KEY{
    ReadHexStringFromConnstansFile("GENESIS_PRIVATE_KEY")};
const std::string GENESIS_PUBLIC_KEY{
    ReadHexStringFromConnstansFile("GENESIS_PUBLIC_KEY")};
