<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>
        <asp:Label ID="Label1" runat="server" Text="Customer Id"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="Button1_Click" />
        <br />
        <asp:Button ID="Button2" runat="server" Text="Add" />
        <asp:Button ID="Button3" runat="server" Text="Edit" />
        <asp:Button ID="Button4" runat="server" Text="Delete" />
    </form>
</body>
</html>
