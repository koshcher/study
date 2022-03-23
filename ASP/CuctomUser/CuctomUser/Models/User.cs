using Microsoft.AspNetCore.Identity;

namespace CuctomUser.Models
{
    public class User : IdentityUser
    {
        public string Status { get; set; }
    }
}
