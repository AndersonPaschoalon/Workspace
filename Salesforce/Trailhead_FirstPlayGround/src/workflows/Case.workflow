<?xml version="1.0" encoding="UTF-8"?>
<Workflow xmlns="http://soap.sforce.com/2006/04/metadata">
    <fieldUpdates>
        <fullName>Set_Case_to_Escalated</fullName>
        <description>trailhead exercise 
https://trailhead.salesforce.com/trails/force_com_dev_beginner/modules/business_process_automation/units/workflow?trailmix_creator_id=00550000006gvuAAAQ&amp;trailmix_id=gri-newemployee</description>
        <field>IsEscalated</field>
        <literalValue>1</literalValue>
        <name>Set Case to Escalated</name>
        <notifyAssignee>false</notifyAssignee>
        <operation>Literal</operation>
        <protected>false</protected>
    </fieldUpdates>
    <rules>
        <fullName>Case Escalate on High Priority</fullName>
        <actions>
            <name>Set_Case_to_Escalated</name>
            <type>FieldUpdate</type>
        </actions>
        <actions>
            <name>Follow_Up_on_Escalated_Case</name>
            <type>Task</type>
        </actions>
        <active>true</active>
        <criteriaItems>
            <field>Case.Priority</field>
            <operation>equals</operation>
            <value>High</value>
        </criteriaItems>
        <criteriaItems>
            <field>Case.IsClosed</field>
            <operation>equals</operation>
            <value>False</value>
        </criteriaItems>
        <description>Trailhead exercise test
https://trailhead.salesforce.com/trails/force_com_dev_beginner/modules/business_process_automation/units/workflow?trailmix_creator_id=00550000006gvuAAAQ&amp;trailmix_id=gri-newemployee</description>
        <triggerType>onCreateOrTriggeringUpdate</triggerType>
    </rules>
    <tasks>
        <fullName>Follow_Up_on_Escalated_Case</fullName>
        <assignedTo>anderson.paschoalon@resourceful-badger-77464.com</assignedTo>
        <assignedToType>user</assignedToType>
        <description>trailhead exercise
https://trailhead.salesforce.com/trails/force_com_dev_beginner/modules/business_process_automation/units/workflow?trailmix_creator_id=00550000006gvuAAAQ&amp;trailmix_id=gri-newemployee</description>
        <dueDateOffset>0</dueDateOffset>
        <notifyAssignee>false</notifyAssignee>
        <priority>Normal</priority>
        <protected>false</protected>
        <status>Not Started</status>
        <subject>Follow Up on Escalated Case</subject>
    </tasks>
</Workflow>
