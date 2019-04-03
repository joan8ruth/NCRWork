<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1"  runat="server">
        <pre>
        <p>
            Student details</p>
        <p>
            Student Id   :<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1" ErrorMessage="!" ForeColor="#CC3300"></asp:RequiredFieldValidator>
            <br />
            Student Name :<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <br />
            Phone Number : <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
            <br />
            Email Id     :<asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
            <br />
            Address      :<asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
            <br />

        </p>
        <asp:Button ID="Button1" runat="server"  Text="Sumbit" OnClick="Button1_Click" />
        <br /><br />
        <asp:Button ID="Button2" runat="server" Text="Reset" OnClick="Button2_Click1" />
        <br /><br />
        <asp:Button ID="Button3" runat="server" Text="Display" OnClick="Button3_Click" />
        <br /><br />
        <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="Delete" />
        
        <br />
        </pre>
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
    </form>

</body>
</html>
