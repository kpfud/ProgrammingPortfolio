document.addEventListener("DOMContentLoaded", function() {
    let newCount = parseInt(document.getElementById("new-count").textContent);

    document.getElementById("increment").addEventListener("click", function() {
        newCount++;
        document.getElementById("new-count").textContent = newCount;
    });

    document.getElementById("decrement").addEventListener("click", function() {
        if (newCount > 0) {
            newCount--;
        }
        document.getElementById("new-count").textContent = newCount;
    });

    document.getElementById("save").addEventListener("click", async function () {
        const url = this.getAttribute("data-url");


        const response = await fetch(url, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ new_count: newCount }),
        });

        if (response.ok) {
            alert("Count updated successfully!");
            window.location.reload();
        } else {
            alert("Error updating count.");
        }
    });
});